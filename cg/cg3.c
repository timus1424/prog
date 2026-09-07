#include <graphics.h>
#include <stdio.h>
#include <math.h>

// DDA Line Drawing Algorithm
void DDA(int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = xa, y = ya;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)x, (int)y, WHITE);
        printf("Step %d: (%f, %f)\n", i, x, y);
        x += xinc;
        y += yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    DDA(100, 100, 500, 400);  // example line

    getch();   // wait for key press
    closegraph();
    return 0;
}
