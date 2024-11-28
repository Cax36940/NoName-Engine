#pragma once
#include "Vector3.hpp"


class ColliderComponent;

class Octree {
    /* [WARNING]
     There may be a lack of precision if colliders have a large areas

            |       |  _____|_______|__
           _|_______|_|___  | .     |  |
          | |     . | |___|_|_______|__|
          |_|_______|_____| |       |
            |       |       |       |

     In this case both colliders overlaps but they will not detect each other.
    */

private:

    struct OctreeNode {
        OctreeNode() : children_index{ 0, 0, 0, 0, 0, 0, 0, 0 } {};
        union
        {
            size_t children_index[8]; // Children ordered with 0b000 and 0b111 corners opposite to each other
            ColliderComponent* colliders[4];
        };
    };

    std::vector<OctreeNode> tree_nodes;
    Vector3 position;
    Vector3 size;

    bool is_node_splitted(const OctreeNode& node);

    void split(size_t nodeIndex, const Vector3& position, const Vector3& size);

    bool add_collider_to_node(ColliderComponent& collider, size_t nodeIndex, const Vector3& position, const Vector3& size);

    void get_overlapping_colliders(const ColliderComponent& collider, std::vector<ColliderComponent*>& collidersVec, size_t nodeIndex, const Vector3& node_position, const Vector3& node_size);

public:
    Octree() = default;
    Octree(size_t collider_count, const Vector3& position, const Vector3& size) : position(position), size(size)
    {
        tree_nodes.reserve((collider_count / 4) + 1);
        tree_nodes.emplace_back();
    };

    void add_collider(ColliderComponent& collider) { add_collider_to_node(collider, 0, position, size); }

    void get_overlapping_colliders(const ColliderComponent& collider, std::vector<ColliderComponent*>& overlapping_colliders) 
    {
        get_overlapping_colliders(collider, overlapping_colliders, 0, position, size);
    }
};