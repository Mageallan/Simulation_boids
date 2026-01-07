#pragma once 
#include "Rule.h"

namespace bd {

class Separation : public Rule {
    private: 
        float separationDistance; 
    
    public: 
        Separation(float separationDistance);
        Vec2<float> apply(const Boid& boid, const DynamicArray<Boid>& neighbors) const override;
};

} // namespace bd