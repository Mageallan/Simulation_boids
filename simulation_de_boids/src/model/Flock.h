#pragma once

#include "DynamicArray.h"
#include "Boid.h"

namespace bd {

class Flock {
private:
    db::DynamicArray<db::Boid> boids;

public:
    Flock() {}

    void addBoid(const db::Boid& b) {
        boids.push_back(b);
    }

    int size() const {
        return boids.size();
    }

    db::Boid& operator[](int index) {
        return boids[index];
    }

    const db::Boid& operator[](int index) const {
        return boids[index];
    }
};

} // namespace bd
