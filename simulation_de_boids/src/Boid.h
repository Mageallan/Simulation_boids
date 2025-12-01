#pragma once
#include "Vec2.h"
class Boid {
	Vec2 position;
	Vec2 speed;
	float perception_radius;

public:
	void position_incrementation(float delta_t);
	void speed_incrementation(float coef);

};