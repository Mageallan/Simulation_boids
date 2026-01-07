#pragma once

#include "util/DynamicArray.h"
#include "Boid.h"

namespace bd {

class Flock {
private:
    DynamicArray<Boid> boids;

public:
    Flock(int count = 50); 

    void addBoid(const Boid& b);

	void addRandomBoid();
	void removeLastBoid();

    int size() const;

    Boid& operator[](int index);
    const Boid& operator[](int index) const;

    const DynamicArray<Boid>& getBoids() const;

	DynamicArray<Boid> findNeighbors(int index, float radius) const;
};





} // namespace bd
