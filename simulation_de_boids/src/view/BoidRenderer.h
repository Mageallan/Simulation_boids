#pragma once
#include <SFML/Graphics.hpp>
#include "../model/Boid.h"

class BoidRenderer {
public:
    static sf::ConvexShape makeShape(const bd::Boid& b);
};
