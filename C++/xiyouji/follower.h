//---------------------------------------------------------------------------
#ifndef followerH
#define followerH
//---------------------------------------------
#pragma once
#include "monster.h"
//---------------------------------------------------------------------------
class FollowerMonster:public Monster
{
private:
	string _newName;
	string _monkName;
public:
	FollowerMonster(string name, int power, string place, string newname, string monkName);
      void onLose(Game & game, Actors & winners, Weapons & weapons);
      void onKilled(Game & game, Actors & winners);
};
//---------------------------------------------------------------------------
#endif
