#pragma once

#include "../Vec2.h"
#include "../Boid.h"
#include "../DynamicArray.h"


namespace bd {

    class Rule {
    public:
        virtual ~Rule() = default;

        // Renvoie un vecteur représentant la force à appliquer au boid
        virtual Vec2<float> apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const = 0;
    };



} // namespace bd

