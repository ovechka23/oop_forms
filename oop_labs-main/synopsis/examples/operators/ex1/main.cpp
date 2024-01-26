#include "complex.h"

int main() {
  Complex a(1, 2);
  Complex b(3, 4);

  Complex c = (double)1 + a;
  std::cout << (double)c << '\n';
}
