#include "Simulation.h"

namespace bd {

Simulation::Simulation(Flock& flock,Settings& settings)
    : flock(flock),
      settings(settings),
      world(settings.windowWidth, settings.windowHeight),
      cohesionRule(),                     
      separationRule(settings.separationDistance), 
      alignmentRule(),                    
      deltaTime(settings.deltaTime)
{}


Vec2<float> Simulation::computeRuleForces(
    const Boid& b,
    const DynamicArray<Boid>& neighbors) const 
{
    Vec2<float> total(0.f, 0.f);

    // Aucun voisin → aucune force
    if (neighbors.size() == 0)
        return total;

    // Cohésion
    total += cohesionRule.apply(b, neighbors) * settings.cohesionWeight;

    // Séparation
    total += separationRule.apply(b, neighbors) * settings.separationWeight;

    // Alignement
    total += alignmentRule.apply(b, neighbors) * settings.alignmentWeight;

    return total;
}

Vec2<float> Simulation::clampSpeed(const Vec2<float>& v) const {
    float len = v.norme();

    // Si la vitesse est trop grande
    if (len > settings.maxSpeed)
        return v.normalized() * settings.maxSpeed;

    // Si la vitesse est trop faible
    if (len < settings.minSpeed)
        return v.normalized() * settings.minSpeed;

    return v;
}


Vec2<float> Simulation::limitForce(const Vec2<float>& f) const {
    float len = f.norme();
    if (len > settings.maxAcceleration)
        return f.normalized() * settings.maxAcceleration;
    return f;
}

void Simulation::update(const Settings& settings) {
    DynamicArray<Vec2<float>> nextVel;

    // 1. Calcul des nouvelles vitesses
    for (int i = 0; i < flock.size(); ++i) {
        Boid& b = flock[i];

        // Trouver les voisins
        DynamicArray<Boid> neighbors =
            flock.findNeighbors(i, settings.perceptionRadius);

        // Calculer les forces
        Vec2<float> force = computeRuleForces(b, neighbors);

        force = limitForce(force);

        Vec2<float> desired = b.velocity + force;

        // Nouvelle vitesse
        Vec2<float> steering = desired - b.velocity;

        steering = limitForce(steering);

        Vec2<float> newVel = b.velocity + steering;

        // Limiter la vitesse
        newVel = clampSpeed(newVel);

        nextVel.push_back(newVel);
    }

    // 2. Mise à jour des positions
    for (int i = 0; i < flock.size(); ++i) {
        Boid& b = flock[i];
        b.velocity = nextVel[i];
        b.position += b.velocity * settings.deltaTime;
        world.handleBounce(b);
    }
}



World& Simulation::getWorld() {
    return world;
}

Flock& Simulation::getFlock() {
    return flock;
}

const Settings& Simulation::getSettings() const {
    return settings;
}

const Cohesion& Simulation::getCohesionRule() const {
    return cohesionRule;
}

const Separation& Simulation::getSeparationRule() const {
    return separationRule;
}

const Alignement& Simulation::getAlignementRule() const {
    return alignmentRule;
}

float Simulation::getDeltaTime() const {
    return deltaTime;
}

const World& Simulation::getWorld() const {
    return world;
}

const Flock& Simulation::getFlock() const {
    return flock;
}



} // namespace bd
