#pragma once
#include "../model/simulation/Simulation.h"
#include "../view/SimulationView.h"
#include "../config/Settings.h"
#include <SFML/Graphics.hpp>

class Controller {
public:
    Controller(bd::Simulation& sim, SimulationView& view, bd::Settings& settings);

    void handleInput();          
    void update();                
    void render();                
    void run();                   

private:

private:
    sf::Clock inputClock;
    float inputDelay = 0.1f;

    bd::Simulation& simulation;
    SimulationView& view;
    bd::Settings& settings;
    sf::RenderWindow window;
};
