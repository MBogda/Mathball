#include <iostream>
#include <SFML/Graphics.hpp>

using ui = unsigned int;
const ui winW = 800;
const ui winH = 600;
const ui goalW = 50;
const ui goalH = 200;

int main()
{
    sf::RenderWindow window(sf::VideoMode(winW, winH), "Mathball");
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape goalL(sf::Vector2f(goalW, goalH));
    goalL.setFillColor(sf::Color(130, 150, 200));
    goalL.setOutlineThickness(-2);
    goalL.setOutlineColor(sf::Color::Black);
    goalL.setPosition(0, (winH + goalH) / 2 - goalH);

    sf::RectangleShape goalR = goalL;
    goalR.setPosition(winW - goalW, (winH + goalH) / 2 - goalH);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if (event.key.code != sf::Keyboard::Escape)
                    break;
                // else code below runs
            case sf::Event::Closed:
                //TODO: вызвать окно предупреждения о выходе
                window.close();
                break;
            default:
                break;
            }
        }

        //draw objects
        window.clear(sf::Color(0, 180, 0));

        window.draw(goalL);
        window.draw(goalR);

        window.display();
    }

    return 0;
}
