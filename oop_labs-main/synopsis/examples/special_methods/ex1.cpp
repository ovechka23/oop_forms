#include <iostream>
using namespace std;

class Complex
{
  double r, i;
  int* mas;

public:
  //                          complex variable
  //                            |
  //                            | variable
  //                            |  |
  Complex(double r, double i) : r(_r), i(i)
  //                              |
  //                           copying
  {
    cout << "Object was created " << r << " + i*" << i << endl;
    mas = new int;
  }

  ~Complex()
  {
    cout << "Object was destroyed" << endl;
    delete mas;
  }

  void Add(Complex& c)
  {
    r += c.r;
    i += c.i;
  }

  Complex Inversed()
  {
    Complex x(i, r);
    // Complex(*this) - явный вызов конструктора копирования
    return x; // констркутор копирования вызывается при возвращении
  }
};


int main()
{
  Complex a(1, 2);
  Complex b(3, 4);

  a.Add(b);
  // при передаче объекта как параметра в функцию происходит вызов
  // конструктора копирования

  b = a.Inverse();
}
