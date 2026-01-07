#pragma once

#include "util/Vec2.h"

namespace bd {

class Boid {
public:
    Vec2<float> position;
    Vec2<float> velocity;

    Boid(const Vec2<float>& pos = {0.f, 0.f},const Vec2<float>& vel = {0.f, 0.f}) : position(pos), velocity(vel) {}
};

} // namespace bd
