#include <iostream>

#include "stack.h"

int main()
{
	Stack<const char*> s1;
	s1.append("Igor");
	s1.append("Semikin");
	s1.append("Anatolievich");
	s1.print();

	Stack<int> s2;
	s2.append(1);
	s2.append(2);
	s2.append(3);
	s2.print();
}