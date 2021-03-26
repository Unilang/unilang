#include <string>
#include <iostream>
#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>



int main()
{
    
    auto video_mode = sf::VideoMode(200, 200); 
    sf::RenderWindow window(video_mode,"hello");
    
    //create line
    std::vector<sf::Vertex> line =
    {
        sf::Vertex(sf::Vector2f(10, 10)),
        sf::Vertex(sf::Vector2f(150, 150)),
        sf::Vertex(sf::Vector2f(200, 50),sf::Color::Red),
        sf::Vertex(sf::Vector2f(10, 10)),
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(line.data(), line.size(), sf::LineStrip);
        window.display();
    }

    return 0;
}
