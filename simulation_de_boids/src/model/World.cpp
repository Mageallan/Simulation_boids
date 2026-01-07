#include "World.h"

namespace bd {

World::World(float width, float height)
    : width(width), height(height) {}


float World::getWidth() const {
    return width;
}

float World::getHeight() const {
    return height;
}

void World::handleBounce(Boid& b) const {
    if (b.position.x < 0) {
        b.position.x = 0;
        b.velocity.x *= -1.0f;
    }
    if (b.position.x > width) {
        b.position.x = width;
        b.velocity.x *= -1.0f;
    }

    if (b.position.y < 0) {
        b.position.y = 0;
        b.velocity.y *= -1.0f;
    }
    if (b.position.y > height) {
        b.position.y = height;
        b.velocity.y *= -1.0f;
    }
}






} // namespace bd
