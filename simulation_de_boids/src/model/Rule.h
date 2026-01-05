#pragma once

#include "Vec2.h"
#include "Boid.h"
#include "Flock.h"

namespace bd {

class Rule {
public:
    virtual ~Rule() {}

    // Calcule la force appliquée à un boid selon la règle
    virtual Vec2<float> compute(const db::Boid& self, const db::Flock& flock) const = 0;
};

}
