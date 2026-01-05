#pragma once

#include "DynamicArray.h"
#include "Boid.h"

namespace bd {

	class Flock {
	private:
		bd::DynamicArray<bd::Boid> boids;

	public:
		Flock() {}

		void addBoid(const bd::Boid& b) {
			boids.push_back(b);
		}

		int size() const {
			return boids.size();
		}

		bd::Boid& operator[](int index) {
			return boids[index];
		}

		const bd::Boid& operator[](int index) const {
			return boids[index];
		}
	};

} // namespace bd
