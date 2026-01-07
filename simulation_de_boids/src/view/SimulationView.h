#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "../model/Flock.h"
#include "../config/Settings.h"

class SimulationView {
public:
    SimulationView();

    void draw(sf::RenderWindow& window,
              const bd::Flock& flock,
              const bd::Settings& settings);

private:
    sf::Font font;
    sf::Text debugText;

    void updateDebugText(const bd::Settings& settings, const bd::Flock& flock);

};
