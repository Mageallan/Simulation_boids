#pragma once

#include "../Flock.h"
#include "../../config/Settings.h"
#include "../rules/Cohesion.h"
#include "../rules/Separation.h"
#include "../rules/Alignement.h"
#include "../World.h"

namespace bd {

class Simulation {
private:
    Flock& flock;
    Settings& settings;
    World world;

    // Les règles de comportement
    Cohesion cohesionRule;
    Separation separationRule;
    Alignement alignmentRule;

    float deltaTime;

public:
    Simulation(Flock& flock, Settings& settings);

    void update(const Settings& settings);  

    //getters
    World& getWorld();
    Flock& getFlock();
    const Settings& getSettings() const;
    const Cohesion& getCohesionRule() const;
    const Separation& getSeparationRule() const;
    const Alignement& getAlignementRule() const;
    float getDeltaTime() const;
    const World& getWorld() const;
    const Flock& getFlock() const;



private:
    Vec2<float> computeRuleForces(const Boid& b, const DynamicArray<Boid>& neighbors) const;
    Vec2<float> clampSpeed(const Vec2<float>& v) const;
    Vec2<float> limitForce(const Vec2<float>& f) const;
};

} // namespace bd
