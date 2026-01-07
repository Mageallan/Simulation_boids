#include "Alignement.h"

namespace bd {

Vec2<float> Alignement::apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const {
    size_t count = neighbors.size();
    if (count == 0)
        return Vec2<float>(0.f, 0.f);

    Vec2<float> sum(0.f, 0.f);

    for (size_t i = 0; i < count; ++i) {
        // Différence de vitesse
        sum += (neighbors[i].velocity - boid.velocity);
    }

    // Moyenne
    return (sum / static_cast<float>(count));
 
}

} // namespace bd
