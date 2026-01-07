#include "SimulationView.h"
#include "BoidRenderer.h"

SimulationView::SimulationView() {
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");

    debugText.setFont(font);
    debugText.setCharacterSize(16);
    debugText.setFillColor(sf::Color::White);
    debugText.setPosition(10.f, 10.f);
}

void SimulationView::updateDebugText(const bd::Settings& settings,
                                     const bd::Flock& flock)
{
    std::stringstream ss;

    ss << "Boids (+/-): " << flock.size() << "\n";
    ss << "Cohesion (1/2): " << settings.cohesionWeight << "\n";
    ss << "Separation (3/4): " << settings.separationWeight << "\n";
    ss << "Alignment (5/6): " << settings.alignmentWeight << "\n";
    ss << "Radius (Up/Down): " << settings.perceptionRadius << "\n";
    ss << "dmin (Left/Right): " << settings.separationDistance << "\n";
    ss << "maxSpeed (A/Z): " << settings.maxSpeed << "\n";
    ss << "minSpeed (E/R): " << settings.minSpeed << "\n";

    debugText.setString(ss.str());
}

void SimulationView::draw(sf::RenderWindow& window,
                          const bd::Flock& flock,
                          const bd::Settings& settings)
{
    // Dessiner les boids
    for (int i = 0; i < flock.size(); ++i) {
        auto shape = BoidRenderer::makeShape(flock[i]);
        window.draw(shape);
    }

    // Mettre à jour et dessiner le texte
    updateDebugText(settings, flock);
    window.draw(debugText);
}
