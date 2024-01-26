#pragma once
#include "unit.h"

class Archer : public Unit
{
	int range, ammo;
public:
	Archer(int hp, int atkDmg, int mp, int pos, int range, int ammo);
	void RngAtk(Unit& enemy);
	void Prnt();
};

