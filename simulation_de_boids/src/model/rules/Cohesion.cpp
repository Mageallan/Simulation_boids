#include "Cohesion.h"

namespace bd {

Vec2<float> Cohesion::apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const {

    if (neighbors.size() == 0)
        return Vec2<float>(0.f, 0.f);

    Vec2<float> sum(0.f, 0.f);

    for (int i = 0; i < neighbors.size(); ++i) {
        sum += (neighbors[i].position - boid.position);
    }

    return (sum / (float)neighbors.size()) * weight;
}

} // namespace bd
