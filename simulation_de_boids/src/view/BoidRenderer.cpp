#include "BoidRenderer.h"
#include <cmath>

sf::ConvexShape BoidRenderer::makeShape(const bd::Boid& b) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);

    float size = 8.f;

    // Triangle isocèle pointant vers la droite
    triangle.setPoint(0, sf::Vector2f(size, 0));        // pointe
    triangle.setPoint(1, sf::Vector2f(0, size / 2));    // bas
    triangle.setPoint(2, sf::Vector2f(0, -size / 2));   // haut

    triangle.setFillColor(sf::Color::White);

    triangle.setPosition(b.position.x, b.position.y);

    float angle = std::atan2(b.velocity.y, b.velocity.x) * 180.f / 3.14159f;
    triangle.setRotation(angle);

    return triangle;
}

