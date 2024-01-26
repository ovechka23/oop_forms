#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Figures.h"

int main()
{
    int winw = 800, winh = 600;
    initwindow(winw, winh, "oop_lab2", 350, 100);

    const int count = 4;
    Figure* figures[count] = {
        new Circ(400, 300, 0x800080, 200),
        new Rect(250, 150, 400, 200, 0xe0ffff),
        new Triangle(40, 40, 500, 300, 50, 550, 0xff1493),
        new Trapezoid(200, 200, 300, 300, 50, -100, 0xffff00c8),
    };

    while (true)
    {
        char ch = getch() - '1';
        setbkcolor(0x000000);
        cleardevice();
        if (ch >=5) break;
        for (int i = 0; i < count; i++)
        {
            if (ch == i or ch == count)
            {
                figures[i]->draw();
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        delete figures[i];
    }
}
