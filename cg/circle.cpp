#include <SFML/Graphics.hpp>
#include <iostream>

void drawCircle(sf::RenderWindow &window, int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r; // initial decision parameter

    while (x <= y) {
        // Plot the 8 symmetric points
        sf::Vertex points[] = {
            sf::Vertex(sf::Vector2f(xc + x, yc + y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc - x, yc + y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc + x, yc - y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc - x, yc - y), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc + y, yc + x), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc - y, yc + x), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc + y, yc - x), sf::Color::Magenta),
            sf::Vertex(sf::Vector2f(xc - y, yc - x), sf::Color::Magenta)
        };
        window.draw(points, 8, sf::Points);

        // Print values to understand progression
        std::cout << "x=" << x << " y=" << y << " p=" << p << "\n";

        // Update decision parameter and coords
        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Midpoint Circle Drawing");
    int xc = 400, yc = 300, r = 100; // center and radius

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        drawCircle(window, xc, yc, r);
        window.display();
    }
    return 0;
}
