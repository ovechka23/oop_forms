#pragma once

class Figure
{
protected:
    double x, y;
    double size;
    int color;

public:
    Figure(double x = 0, double y = 0, int color = 0x000000, double size = 1);

    double get_x();
    double get_y();
    double get_size();
    int get_color();

    void move_to(double x, double y);
    void move_by(double x, double y);
    void set_x(double x);
    void set_y(double y);
    void set_color(int color);
    void set_size(double size);

    virtual void draw() = 0;
};


class Circ : public Figure
{
public:
    using Figure::Figure;
    void draw();
};


class Rect : public Figure
{
protected:
    double w, h;

public:
    Rect(double x, double y, double w, double h, int color);

    double get_w();
    double get_h();

    void set_sides(double w, double h);
    void set_w(double w);
    void set_h(double h);

    void draw();
};


class Triangle : public Figure
{
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle(double x1, double y1, double x2, double y2,
        double x3, double y3, int color);

    void move_to(double x1, double y1, double x2, double y2, double x3, double y3);
    void move_by(double x1, double y1, double x2, double y2, double x3, double y3);

    void draw();
};

class Rhomb : public Rect
{
public:
    using Rect::Rect;

    void draw();
};
