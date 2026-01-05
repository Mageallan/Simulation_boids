#include "UIRightPanel.h"
#include <sstream>

namespace bd {

    UIRightPanel::UIRightPanel(SettingsController& settingsCtrl)
        : settings(settingsCtrl)
    {
        font.loadFromFile("arial.ttf");

        background.setSize(sf::Vector2f(200, 600));
        background.setPosition(800, 0);
        background.setFillColor(sf::Color(40, 40, 40));

        title.setFont(font);
        title.setString("PARAMETRES");
        title.setCharacterSize(20);
        title.setPosition(810, 10);

        parameters.setFont(font);
        parameters.setCharacterSize(16);
        parameters.setPosition(810, 50);

        updateText();
    }

    void UIRightPanel::handleInput(const sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {

            switch (event.key.code) {
            case sf::Keyboard::Num1: settings.changeCohesionWeight(+0.01f); break;
            case sf::Keyboard::Num2: settings.changeCohesionWeight(-0.01f); break;

            case sf::Keyboard::Num3: settings.changeSeparationWeight(+0.01f); break;
            case sf::Keyboard::Num4: settings.changeSeparationWeight(-0.01f); break;

            case sf::Keyboard::Num5: settings.changeAlignmentWeight(+0.01f); break;
            case sf::Keyboard::Num6: settings.changeAlignmentWeight(-0.01f); break;

            case sf::Keyboard::Add: settings.changeBoidCount(+1); break;
            case sf::Keyboard::Subtract: settings.changeBoidCount(-1); break;

            default: break;
            }

            updateText();
        }
    }

    void UIRightPanel::updateText() {
        std::ostringstream oss;

        oss << "Boids: " << settings.getBoidCount() << "\n\n"
            << "Cohesion: " << settings.getCohesionWeight() << "\n"
            << "Separation: " << settings.getSeparationWeight() << "\n"
            << "Alignment: " << settings.getAlignmentWeight() << "\n\n"
            << "Touches:\n"
            << "1/2 : Cohesion +/-\n"
            << "3/4 : Separation +/-\n"
            << "5/6 : Alignment +/-\n"
            << "+/- : Boids +/-";

        parameters.setString(oss.str());
    }

    void UIRightPanel::draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(title);
        window.draw(parameters);
    }

}
