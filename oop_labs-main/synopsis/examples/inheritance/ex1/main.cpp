#include "unit.h"
#include "archer.h"

int main()
{
	Unit* arr[2];

	arr[0] = new Unit(12, 2, 2, 0);
	arr[1] = new Archer(15, 3, 1, 5, 12, 3);

	//a.Move(1);
	//a.Prnt();

	//Archer b(15, 3, 1, 5, 12, 3);
	//b.Move(-1);
	//b.Prnt();

	//a.Atk(b);
	//b.RngAtk(a);

	//a.Prnt();
	//b.Prnt();

	for (int i = 0; i < 2; i++)
		// dynamic polymorphism
		arr[i]->Prnt();

	for (int i = 0; i < 2; i++)
		delete arr[i];

	return 0;
}