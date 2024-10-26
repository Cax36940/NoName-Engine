#include <ofGraphics.h>
#include "ConvexHull.hpp"
#include <stack>

static const Vector3* anchorPoint;


int orientation(const Vector3* p, const Vector3* q, const Vector3* r) {
    float val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Comparison function to sort points by polar angle with the anchor
static bool compare(const Vector3* p1, const Vector3* p2) {
    int o = orientation(anchorPoint, p1, p2);
    if (o == 0) // If collinear, return the point that is closer to anchorPoint
        return Vector3::norm2(*anchorPoint - *p1) < Vector3::norm2(*anchorPoint - *p2);
    return (o == 2); // Return true if p1 is counterclockwise to p2
}


void ConvexHull::set_positions(const std::vector<const Vector3*>& pos) {
	positions = pos;
}


void ConvexHull::set_color(const float& r, const float& g, const float& b) {
	color = glm::vec3(r, g, b);
}

void ConvexHull::set_visible_outline(bool new_visible)
{
    visible_outline = new_visible;
}

void ConvexHull::draw()
{
	if (!visible) {
		return;
	}

    std::vector<const Vector3*> hullPoints;

    int n = positions.size();
    if (n < 3) return; // Convex hull is not possible with fewer than 3 points

    int minY = 0;
    for (int i = 1; i < n; i++) {
        if (positions[i]->y < positions[minY]->y || (positions[i]->y == positions[minY]->y && positions[i]->x < positions[minY]->x)) {
            minY = i;
        }
    }
    std::swap(positions[0], positions[minY]);
    anchorPoint = positions[0];

    // Step 2: Sort the remaining points based on the polar angle with anchorPoint
    std::sort(positions.begin() + 1, positions.end(), compare);

    // Step 3: Create a stack and process the sorted points
    std::stack<const Vector3*> hull;
    hull.push(positions[0]);
    hull.push(positions[1]);
    hull.push(positions[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1) {
            const Vector3* top = hull.top();
            hull.pop();
            const Vector3* nextToTop = hull.top();
            if (orientation(nextToTop, top, positions[i]) == 2) {
                hull.push(top);
                break;
            }
        }
        hull.push(positions[i]);
    }

    // Step 4: Transfer stack to hullPoints vector for drawing
    while (!hull.empty()) {
        hullPoints.push_back(hull.top());
        hull.pop();
    }

	ofSetColor(color.r, color.g, color.b);
    ofFill();
    ofBeginShape();
    for (const Vector3* point : hullPoints) {
        ofVertex(point->x, point->y);
    }
    ofEndShape(true); // Close the shape

    // Draw outline
    if (visible_outline) {
        ofSetColor(ofColor(255,155,0));  // Outline color (orange)
        ofNoFill();     // Disable fill for outline
        ofSetLineWidth(5);  // Set the line width for the outline
    
        ofBeginShape();
        for (const Vector3* point : hullPoints) {
            ofVertex(point->x, point->y);
        }
        ofEndShape(true);  // Close the shape
        ofSetLineWidth(1);
    }
}
