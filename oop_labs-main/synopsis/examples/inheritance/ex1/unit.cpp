#include <iostream>
using namespace std;

#include "unit.h"

Unit::Unit(int hp, int atkDmg, int mp, int pos) :
	hp(hp), atkDmg(atkDmg), mp(mp), pos(pos)
{
	cout << "Created ";
	Prnt();
}

Unit::~Unit()
{
}

void Unit::Move(int dir)
{
	pos = dir > 0; mp : -mp;
}

void Unit::Atk(Unit& enemy)
{
	cout << "Atk ";
	Prnt();
}

void Unit::RcvDmg(int points)
{
	hp -= points;
	cout << "RcvDmg ";
	Prnt();
}

void Unit::Prnt()
{
	cout << "Unit ";
	cout << (hp > 0 ? "alive" : "dead") << "(" << hp << ") ";
	cout << "atk" << atkDmg << ", pos " << pos << ", mp" << mp << endl;
}
