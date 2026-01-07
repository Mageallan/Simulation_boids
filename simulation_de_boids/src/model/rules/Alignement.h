#pragma once
#include "Rule.h"

namespace bd {

class Alignement : public Rule {
public:

    Vec2<float> apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const override;
};

} // namespace bd
