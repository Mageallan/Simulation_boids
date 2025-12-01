#pragma once
#include "Boid.h"
#include "DynamicArray.h"
template<typename T>
class Flock {

	DynamicArray<T> flock;

public : 
	Flock();
	~Flock();

	void addBoid(Boid& boid);
	void suppBoid(Boid& boid)
};