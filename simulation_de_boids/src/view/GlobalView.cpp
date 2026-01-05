#include "GlobalView.h"

namespace bd {

    GlobalView::GlobalView(SimulationController& simCtrl, SettingsController& setCtrl)
        : window(sf::VideoMode(1000, 600), "Boids Simulation"),
        simController(simCtrl),
        settingsController(setCtrl),
        rightPanel(setCtrl),
        boidRenderer()
    {
    }

    void GlobalView::run() {
        sf::Clock clock;

        while (window.isOpen()) {
            float dt = clock.restart().asSeconds();

            processEvents();
            update(dt);
            render();
        }
    }

    void GlobalView::processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            // Interaction clavier ? SettingsController
            rightPanel.handleInput(event);
        }
    }

    void GlobalView::update(float dt) {
        simController.updateSimulation(dt);
    }

    void GlobalView::render() {
        window.clear(sf::Color::Black);

        // Affichage des boids
        boidRenderer.draw(window, simController.getFlock());

        // Affichage du panneau latéral
        rightPanel.draw(window);

        window.display();
    }

}
