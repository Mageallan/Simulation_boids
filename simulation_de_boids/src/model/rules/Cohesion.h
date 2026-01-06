#pragma once
#include "Rule.h"
#include "../../config/Settings.h"

namespace bd {

class Cohesion : public Rule {
    private:
        Settings settings;

public:
    float weight = settings.cohesionWeight;

    Vec2<float> apply(const Boid& boid,const DynamicArray<Boid>& neighbors) const override;
};

} // namespace bd
