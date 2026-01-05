#pragma once
#include "Rule.h"

namespace bd {

class Cohesion : public Rule {
public:
    Vec2<float> compute(const db::Boid& self, const db::Flock& flock) const override {
        Vec2<float> sum(0.f, 0.f);
        int count = 0;

        for (int i = 0; i < flock.size(); ++i) {
            const db::Boid& other = flock[i];
            if (&other == &self) continue;

            float dist = (other.position - self.position).length();
            if (dist < flock.settings->perceptionRadius) {
                sum += (other.position - self.position);
                count++;
            }
        }

        if (count == 0) return Vec2<float>(0.f, 0.f);
        return sum / static_cast<float>(count);
    }
};

} // namespace bd
