#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>
// DDA Line Drawing Algorithm
void DDA(sf::RenderWindow &window, int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = xa, y = ya;

    for (int i = 0; i <= steps; i++) {
	std::cout<<"Step"<<i<<": ("<<x<<", "<<y<<")/n";
        sf::Vertex point(sf::Vector2f(x, y), sf::Color::Magenta);
        window.draw(&point, 1, sf::Points);
        x += xinc;
        y += yinc;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DDA Line Drawing");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        DDA(window, 100, 100, 500, 400); // test line
        window.display();
    }
    return 0;
}
