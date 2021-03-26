#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "code/utilities/colors/sfml/sfml_color_pick_grid.hpp"
#include "code/utilities/colors/sfml/sfml_color_pick_hue_changer.hpp"

int main(int argc, char **argv) {
    // Setup a render window
    sf::RenderWindow window(sf::VideoMode(256, 256), "Color Picker");

    // We're using a clock to change the hue dynamically.
    sf::Clock timer;

    auto colors = Sfml_Color_Pick_Grid::Get();

    while (window.isOpen()) {
        sf::Event event;
        // Your typical event loop
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        // Update our colors based on the time passed.
        // I want to cycle all hues in 5 seconds, so dividing the timer.
        Sfml_Color_Pick_Hue_Changer::Modulate(colors, timer.getElapsedTime().asSeconds() / 5);

        // Draw and display our colors
        window.clear();
        window.draw(colors);
        window.display();
    }
}

