#include "Octree.hpp"

 bool Octree::is_node_splitted(const OctreeNode& node)
 {
    // This may not be safe
    return node.children_index[1] - node.children_index[0] == 1;
 }

// Split a tree node into 4 children
void Octree::split(size_t node_index, const Vector3& position, const Vector3& size)
{
    // Save colliders
    ColliderComponent* tmpColliders[4] = {
        tree_nodes[node_index].colliders[0], tree_nodes[node_index].colliders[1],
        tree_nodes[node_index].colliders[2], tree_nodes[node_index].colliders[3]
    };

    // Add 4 child nodes
    size_t firstChildIndex = tree_nodes.size();
    tree_nodes.resize(tree_nodes.size() + 4);

    for (int i = 0; i < 4; ++i)
    {
        tree_nodes[node_index].children_index[i] = firstChildIndex + i;
    }

    // Add the colliders back
    for (int i = 0; i < 4; ++i)
    {
        add_collider_to_node(*tmpColliders[i], node_index, position, size);
    }
}

bool Octree::add_collider_to_node(ColliderComponent& collider, size_t node_index, const Vector3& position, const Vector3& size)
{
    // Case when collider is not in the node
    if (!(abs(collider.GetArea().x() - area.x()) <= area.width() &&
        abs(collider.GetArea().y() - area.y()) <= area.height()))
    {
        return false;
    }

    // Case when node is splitted
    if (is_node_splitted(tree_nodes[node_index]))
    {
        Vector3 new_size(size.x / 2, size.y / 2, size.z / 2);
        Vector3 half_new_size(size.x / 4, size.y / 4, size.z / 4);

        Vector3 new_position[8] = {
            Vector3(position.x - half_new_size.x, position.y - half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y - half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y + half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y + half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y - half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y - half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y + half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y + half_new_size.y, position.z + half_new_size.z)
        };

        for (int i = 0; i < 8; ++i)
        {
        if (add_collider_to_node(collider, tree_nodes[node_index].children_index[i], new_position[i], new_size))
        {
            return true;
        };
        }
        // Should not be reached
        return false;
    }

    // Case when node is not splitted
    for (int i = 0; i < 4; ++i)
    {
        if (tree_nodes[node_index].colliders[i] == nullptr)
        {
            tree_nodes[node_index].colliders[i] = &collider;
            return true;
        }
    }

    // Case when node is full
    split(node_index, position, size);
    return add_collider_to_node(collider, node_index, position, size);
}

void Octree::get_overlapping_colliders(const ColliderComponent& collider, std::vector<ColliderComponent*>& colliders_vec, size_t node_index, const Vector3& position, const Vector3& size)
{
    // Case when collider does not intersect the node
    if (!collider.GetArea().Intersects(nodeArea))
    {
        return;
    }

    // Case when node is splitted
    if (is_node_splitted(tree_nodes[node_index]))
    {
        Vector3 new_size(size.x/2, size.y/2, size.z/2);
        Vector3 half_new_size(size.x / 4, size.y / 4, size.z / 4);

        Vector3 new_position[8] = {
            Vector3(position.x - half_new_size.x, position.y - half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y - half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y + half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y + half_new_size.y, position.z - half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y - half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y - half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x - half_new_size.x, position.y + half_new_size.y, position.z + half_new_size.z),
            Vector3(position.x + half_new_size.x, position.y + half_new_size.y, position.z + half_new_size.z)
        };

        for (int i = 0; i < 4; ++i) {
            get_overlapping_colliders(collider, colliders_vec, tree_nodes[node_index].children_index[i], new_position[i], new_size);
        }

        return;
    }

    // Case when node is not splitted
    for (int i = 0; i < 4; ++i)
    {
        if (tree_nodes[node_index].colliders[i] != nullptr &&
            tree_nodes[node_index].colliders[i] != &collider)
        {
            colliders_vec.push_back(tree_nodes[node_index].colliders[i]);
        }
    }
}
