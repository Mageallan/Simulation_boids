#include "Separation.h"

namespace bd {

    Separation::Separation(float separationDistance)
    : separationDistance(separationDistance) {}


    Vec2<float> Separation::apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const {
    Vec2<float> force(0.f, 0.f);

    for (int i = 0; i < neighbors.size(); ++i) {
        Vec2<float> diff = boid.position - neighbors[i].position;
        float dist = diff.norme();

        if (dist > 0.001f && dist < separationDistance) {

            // Formule imposée par le sujet
            Vec2<float> contrib = diff / (dist * dist);

            // Limitation par voisin (indispensable)
            float maxPerNeighbor = 0.1f; // adapté à amax = 0.1
            if (contrib.norme() > maxPerNeighbor)
                contrib = contrib.normalized() * maxPerNeighbor;

            force += contrib;
        }
    }

    return force;
}



} // namespace bd