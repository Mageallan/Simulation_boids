#pragma once

namespace bd {

class Settings {
public:
    // Window
    float windowWidth  = 800.0f;
    float windowHeight = 600.0f;

    // Physics
    float baseSpeed        = 1.0f;  // vitesse initiale
    float maxSpeed         = 4.0f;  // vmax
    float maxAcceleration  = 0.1f;  // amax
    float minSpeed = 0.5f;  // vmin

    // Rule weights
    float cohesionWeight   = 0.01f;
    float separationWeight = 0.05f;
    float alignmentWeight  = 0.125f;

    // Distances
    float perceptionRadius   = 50.0f; // r
    float separationDistance = 20.0f; // dmin

    // Vision (optionnel, utile si tu veux un cône de vision)
    float visionAngleDeg = 90.0f;
    float visionRange    = 50.0f;

    float deltaTime = 0.016f;

    int initialBoidCount = 50;

    

    Settings() = default;
};

} // namespace bd
