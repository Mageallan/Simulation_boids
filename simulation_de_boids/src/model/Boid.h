#pragma once
#include "Vec2.h"
namespace db {

	class Boid {
		Vec2<double> position;
		Vec2<double> speed;
		float perception_radius;


	public:
		void position_incrementation(float delta_t);
		void speed_incrementation(float coef);

	};

}