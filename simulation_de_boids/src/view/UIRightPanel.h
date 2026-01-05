#pragma once
#include <SFML/Graphics.hpp>
#include "../controller/SettingsController.h"

namespace bd {

    class UIRightPanel {
    private:
        SettingsController& settings;
        sf::Font font;
        sf::RectangleShape background;

        sf::Text title;
        sf::Text parameters;

    public:
        UIRightPanel(SettingsController& settingsCtrl);

        void handleInput(const sf::Event& event);
        void draw(sf::RenderWindow& window);

    private:
        void updateText();
    };

}
