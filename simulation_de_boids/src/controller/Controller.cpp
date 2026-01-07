#include "Controller.h"

Controller::Controller(bd::Simulation& sim, SimulationView& view, bd::Settings& settings)
    : simulation(sim), view(view), settings(settings),
      window(sf::VideoMode(settings.windowWidth, settings.windowHeight), "Boids")
{}

void Controller::handleInput() {

    float dt = inputClock.getElapsedTime().asSeconds();
    if (dt < inputDelay)
        return;

    // --- Nombre de boids (+ / -) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
        simulation.getFlock().addRandomBoid();
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
        simulation.getFlock().removeLastBoid();
        inputClock.restart();
    }

    // --- Cohésion (1 / 2) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num1)) {
        settings.cohesionWeight += 0.01f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num2)) {
        settings.cohesionWeight -= 0.01f;
        inputClock.restart();
    }

    // --- Séparation (3 / 4) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num3)) {
        settings.separationWeight += 0.01f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num4)) {
        settings.separationWeight -= 0.01f;
        inputClock.restart();
    }

    // --- Alignement (5 / 6) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num5)) {
        settings.alignmentWeight += 0.01f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num6)) {
        settings.alignmentWeight -= 0.01f;
        inputClock.restart();
    }

    // --- Rayon de perception (↑ / ↓) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        settings.perceptionRadius += 1.f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        settings.perceptionRadius -= 1.f;
        inputClock.restart();
    }

    // --- Distance minimale (← / →) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        settings.separationDistance -= 1.f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        settings.separationDistance += 1.f;
        inputClock.restart();
    }

    // --- Modifier maxSpeed (A / Z) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        settings.maxSpeed += 0.1f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        settings.maxSpeed -= 0.1f;
        inputClock.restart();
    }

    // --- Modifier minSpeed (E / R) ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        settings.minSpeed += 0.1f;
        inputClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        settings.minSpeed -= 0.1f;
        inputClock.restart();
    }

    // --- Clamp des valeurs ---
    settings.cohesionWeight   = std::clamp(settings.cohesionWeight,   0.f, 1.f);
    settings.separationWeight = std::clamp(settings.separationWeight, 0.f, 1.f);
    settings.alignmentWeight  = std::clamp(settings.alignmentWeight,  0.f, 1.f);

    settings.perceptionRadius   = std::clamp(settings.perceptionRadius,   10.f, 100.f);
    settings.separationDistance = std::clamp(settings.separationDistance, 5.f, 50.f);
    
    settings.maxSpeed = std::clamp(settings.maxSpeed, settings.minSpeed, 20.f);
    settings.minSpeed = std::clamp(settings.minSpeed, 0.1f, settings.maxSpeed);

}



void Controller::update() {
    simulation.update(settings);
}

void Controller::render() {
    window.clear();
    view.draw(window, simulation.getFlock(), settings);
    window.display();
}

void Controller::run() {
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput();
        update();
        render();
    }
}
