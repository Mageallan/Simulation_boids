#pragma once
#include "Separation.h"
#include "config/Settings.h"

namespace bd {

Vec2<float> Separation::apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const {
    Vec2<float> force(0.f, 0.f);

    for (size_t i = 0; i < neighbors.size(); ++i) {
        Vec2<float> diff = boid.position - neighbors[i].position;
        float dist = diff.norme();

        if (dist > 0.001f) {
            force += diff / (dist * dist);
        }
    }

    return force * weight;
}


} // namespace bd