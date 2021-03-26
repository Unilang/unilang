#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>

//jstest-gtk to toy visually
int main(){
    
    while (true){
        
        // Is joystick #0 connected?
        bool connected = sf::Joystick::isConnected(0);
        std::cout << connected << " ";
        
        // How many buttons does joystick #0 support?
        unsigned int buttons = sf::Joystick::getButtonCount(0);
        std::cout << buttons << " ";
        
        // Does joystick #0 define a X axis?
        bool hasX = sf::Joystick::hasAxis(0, sf::Joystick::X);
        std::cout << hasX << " ";
        
        // Is button #2 pressed on joystick #0?
        bool pressed = sf::Joystick::isButtonPressed(0, 2);
        std::cout << pressed << " ";
        
        // What's the current position of the Y axis on joystick #0?
        float position = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
        std::cout << position << " " << std::endl;
        sf::Joystick::update();
    }
}