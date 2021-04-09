//---------------------------------------------------------------------------
#ifndef monkH
#define monkH
//---------------------------------------------------------------------------
#pragma once

#include "actor.h"
//---------------------------------------------------------------------------
class Monk : public Actor
{
private:
	string _monkName;
public:
	string getName();
	Monk(string name, string monkName, int power);
	~Monk();
	void say();
	void patter();
	Actor & operator>> (Weapon & weapon);
      	void onWin(Game & game, Actors & losers, Weapons & weapons);
};
//---------------------------------------------------------------------------
#endif
