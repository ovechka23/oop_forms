#include <iostream>
using namespace std;

#include "archer.h"

Archer::Archer(int hp, int atkDmg, int mp, int pos, int range, int ammo) :
	Unit(hp, atkDmg, mp, pos), range(range), ammo(ammo)
{
	cout << "Last created Unit was Archer (" << ammo << ")" << endl;
}

void Archer::RngAtk(Unit& enemy)
{
	enemy.RcvDmg(atkDmg + 1);
}

void Archer::Prnt()
{
	//((Unit*)this)->Prnt();
	cout << "ammo " << ammo << endl;
}
