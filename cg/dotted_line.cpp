#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

// DDA Line Algorithm with dotted style
void drawDottedLine(sf::RenderWindow &window, int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    int steps = std::max(std::abs(dx), std::abs(dy));

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;

    float x = xa, y = ya;

    for (int i = 0; i <= steps; i++) {
        if (i % 2 == 0) {  
            // plot every alternate point -> dotted effect
            sf::Vertex point(sf::Vector2f(std::round(x), std::round(y)), sf::Color::Cyan);
            window.draw(&point, 1, sf::Points);
        }
        x += xinc;
        y += yinc;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dotted Line (DDA)");
    int xa = 100, ya = 100, xb = 700, yb = 400;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        drawDottedLine(window, xa, ya, xb, yb);
        window.display();
    }
    return 0;
}

/*
🔧 Tweaks for fun
	•	Change the modulus (if (i % 2 == 0)) →
	•	i % 2 → dotted
	•	i % 5 < 3 → dashed (3 on, 2 off)
	•	i % 10 < 7 → longer dash pattern
*/
