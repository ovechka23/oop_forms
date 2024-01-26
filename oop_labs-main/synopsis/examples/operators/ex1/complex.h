#pragma once

#include <iostream>

class Complex
{
  int i, r;
  int* mas;

public:
  Complex();
  Complex(double r, double i);
  ~Complex();

  Complex operator + (Complex& b);
  Complex& operator = (const Complex& c);

  Complex operator + (double b);
  friend Complex operator + (double a, Complex& b);

  operator double();

  void Add(Complex& c);
  Complex Inversed();
};

Complex operator + (double a, Complex& b);
