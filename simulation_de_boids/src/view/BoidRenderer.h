#pragma once
#include <SFML/Graphics.hpp>
#include "../model/Flock.h"

namespace bd {

    class BoidRenderer {
    public:
        void draw(sf::RenderWindow& window, const Flock& flock);
    };

}
