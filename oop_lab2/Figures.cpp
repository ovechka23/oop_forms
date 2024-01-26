#include "Figures.h"

#include <iostream>

#include "graphics.h"

Figure::Figure(double x, double y, int color, double size)
{
    move_to(x, y);
    set_color(color);
    set_size(size);
}

double Figure::get_x()
{
    return x;
}

double Figure::get_y()
{
    return y;
}

double Figure::get_size()
{
    return size;
}

int Figure::get_color()
{
    return color;
}

void Figure::move_to(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Figure::move_by(double x, double y)
{
    this->x += x;
    this->y += y;
}

void Figure::set_x(double x)
{
    this->x = x;
}

void Figure::set_y(double y)
{
    this->y = y;
}

void Figure::set_color(int color)
{
    if(color < 0x000000 or color > 0xffffff) printf("Only value from 0x000000 to 0xffffff");
    this->color = color;
}

void Figure::set_size(double size)
{
    if (size < 0) printf("Only a positive ponumber");
    this->size = size;
}


void Circ::draw()
{
    setcolor(color);
    circle(x, y, size);
}
//---------------------------------------------------------

Rect::Rect(double x, double y, double w, double h, int color)
{
    move_to(x, y);
    set_sides(w, h);
    set_color(color);
    set_size(size);
}

double Rect::get_w()
{
    return w;
}

double Rect::get_h()
{
    return h;
}

void Rect::set_sides(double w, double h)
{
    set_w(w);
    set_h(h);
}

void Rect::set_w(double w)
{
    if (w < 0) printf("Only a positive ponumber");
    this->w = w;
}

void Rect::set_h(double h)
{
    if (w < 0) printf("Only a positive ponumber");
    this->h = h;
}

void Rect::draw()
{
    setcolor(color);
    rectangle(x, y, x + w, y + h);
}
//----------------------------------------------------------

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3, int color)
{
    move_to(x1, y1, x2, y2, x3, y3);
    set_color(color);
}

void Triangle::move_to(double x1, double y1, double x2, double y2, double x3, double y3)
{
    this->x1 = x1;
    this->y1 = y1;

    this->x2 = x2;
    this->y2 = y2;

    this->x3 = x3;
    this->y3 = y3;
}

void Triangle::move_by(double x1, double y1, double x2, double y2, double x3, double y3)
{
    this->x1 += x1;
    this->y1 += y1;

    this->x2 += x2;
    this->y2 += y2;

    this->x3 += x3;
    this->y3 += y3;
}

void Triangle::draw()
{
    int poly[8];

    poly[0] = x1;
    poly[1] = y1;

    poly[2] = x2;
    poly[3] = y2;

    poly[4] = x3;
    poly[5] = y3;

    poly[6] = x1;
    poly[7] = y1;

    setcolor(color);
    drawpoly(4, poly);
}
//-----------------------------------------------------------

Trapezoid::Trapezoid(double x, double y, double w, double h, double dx1, double dx2, int color)
{
    move_to(x, y);
    set_sides(w, h);
    set_dx(dx1, dx2);
    set_color(color);
    set_size(size);
}

void Trapezoid::draw()
{
    int poly[10];

    poly[0] = x;
    poly[1] = y;

    poly[2] = x + w;
    poly[3] = y;

    poly[4] = x + w + dx1;
    poly[5] = y + h;

    poly[6] = x - dx2;
    poly[7] = y + h;

    poly[8] = x;
    poly[9] = y;

    setcolor(color);
    setfillpattern((char*)poly, color);
    fillpoly(5, poly);
}

double Trapezoid::get_w()
{
    return w;
}

double Trapezoid::get_h()
{
    return h;
}

double Trapezoid::get_dx1()
{
    return dx1;
}

double Trapezoid::get_dx2()
{
    return dx2;
}

void Trapezoid::set_sides(double w, double h)
{
    set_w(w);
    set_h(h);
}

void Trapezoid::set_w(double w)
{
    if (w < 0) printf("Only a positive ponumber");
    this->w = w;
}

void Trapezoid::set_h(double h)
{
    if (h < 0) printf("Only a positive ponumber");
    this->h = h;
}

void Trapezoid::set_dx(double dx1, double dx2)
{
    this->dx1 = dx1;
    this->dx2 = dx2;
}
