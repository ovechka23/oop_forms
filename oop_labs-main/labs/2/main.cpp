#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "figures.h"

int main() {
    initwindow(500, 500, "2nd lab", 250, 250);

    const int size = 4;
    Figure* figures[size] = {
        new Circ(250, 250, 0x0000ff, 100),
        new Rect(100, 100, 100, 200, 0x00ff00),
        new Triangle(20, 20, 400, 400, 0, 450, 0xff0000),
        new Rhomb(100, 100, 200, 200, 0xf000ff),
    };

    while (true)
    {
        char sym = getch() - '1';
        setbkcolor(0x000000);
        cleardevice();

        for (int i = 0; i < size; i++)
        {
            if (sym == i or sym == size)
            {
                figures[i]->draw();
            }
        }
    }
}
