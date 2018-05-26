#include <SFML/Graphics.hpp>
#include "Layer.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "Rpg");

    const int level1[] =
    {
        1, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 10, 10, 10, 10, 2, 2, 2, 2, 2, 2,
    };

    Layer layer1;
    if (!layer1.load("tilesets/chemin.png", sf::Vector2u(32, 32), level1, 16, 8))
        return -1;


    // We set framerate to 30 fps because that's enough
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(layer1);
        window.draw(layer2);
        window.display();
    }

    return 0;
}
