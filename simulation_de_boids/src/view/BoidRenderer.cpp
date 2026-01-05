#include "BoidRenderer.h"

namespace bd {

    void BoidRenderer::draw(sf::RenderWindow& window, const Flock& flock) {
        for (const Boid& b : flock.getBoids()) {

            sf::ConvexShape triangle;
            triangle.setPointCount(3);
            triangle.setPoint(0, sf::Vector2f(0, -5));
            triangle.setPoint(1, sf::Vector2f(10, 0));
            triangle.setPoint(2, sf::Vector2f(0, 5));

            triangle.setFillColor(sf::Color::White);

            triangle.setPosition(b.position.x, b.position.y);

            float angle = atan2(b.speed.y, b.speed.x) * 180 / 3.14159f;
            triangle.setRotation(angle);

            window.draw(triangle);
        }
    }

}
