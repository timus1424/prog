#include <SFML/Graphics.hpp>
#include <cmath>

void DDA(sf::RenderWindow &window, int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = xa, y = ya;

    for (int i = 0; i <= steps; i++) {
        sf::Vertex point(sf::Vector2f(x, y), sf::Color::Magenta);
        window.draw(&point, 1, sf::Points);
        x += xinc;
        y += yinc;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DDA Line");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        DDA(window, 100, 100, 500, 400);
        window.display();
    }
    return 0;
}





// #include<stdio.h>
// #include<conio.h>
// #include<graphics.h>
// #define ROUND((int)(a+0.5))

// void DDA(int xa, int ya, int xb, int yb){
//     int dx=xb-xa,dy=yb-ya,steps,i;
//     float xinc,yinc,x=xa,y=ya;
//     putpixel(ROUND(x),ROUND(y),MAGENTA);
//     if(abs(dx)>abs(dy))
//         steps=abs(dx);
//     else
//         steps=abs(dy);
//     xinc=dx/(float)steps;
//     yinc=dy/(float)steps;
//     for(i=1;i<=steps;i++){
//         x+=xinc;
//         y+=yinc;
//         putpixel(ROUND(x),ROUND(y),MAGENTA);
//     }
// }

// void main(){
//     int gd=DETECT,gm;
//     // int xa,ya,xb,yb;
//     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
//     printf("Enter the coordinates of first point(xa,ya): ");
//     scanf("%d%d",&xa,&ya);
//     printf("Enter the coordinates of second point(xb,yb): ");
//     scanf("%d%d",&xb,&yb);
//     DDA(xa,ya,xb,yb);
//     getch();
//     closegraph();
// }
// // void DDA(int xa, inta ya, int xb, int yb)
// // {
// //     int dx, dy, steps, k;
// //     float xinc, yinc, x=xa, y=ya;
// //     dx=xb-xa;
// //     dy=yb-ya;
// //     if(abs(dx)>abs(dy))
// //         steps=abs(dx);
// //     else
// //         steps=abs(dy);
// //     xinc=dx/(float)steps;
// //     yinc=dy/(float)steps;
// //     putpixel(ROUND(x), ROUND(y), 7);
// //     for(k=1; k<=steps; k++)
// //     {
// //         x+=xinc;
// //         y+=yinc;
// //         putpixel(ROUND(x), ROUND(y), 7);
// //     }
// // }
