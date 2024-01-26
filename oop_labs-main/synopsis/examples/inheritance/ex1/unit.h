#pragma once

class Unit
{
protected:
	int hp, dmg, atkDmg, mp, pos;
public:
	Unit(int hp, int atkDmg, int mp, int pos);
	virtual ~Unit();
	void Move(int dir);
	void Atk(Unit& enemy);
	void RcvDmg(int points);
	virtual void Prnt();
};

