#pragma once

#include "../model/Boid.h"

namespace bd {

class World {
private:
    float width;
    float height;

public:
    World(float width, float height);

    float getWidth() const;
    float getHeight() const;

    // Gère les bords (wrap-around)
    void handleBounce(Boid& b) const;
};

} // namespace bd
