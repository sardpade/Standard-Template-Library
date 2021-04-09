//---------------------------------------------------------------------------
#ifndef monsterH
#define monsterH
//---------------------------------------------------------------------------

#pragma once
#include "actor.h"
//---------------------------------------------------------------------------
class Monster : public Actor
{
private:
	string _place;
public:
	Monster(string namem, bool gender, int power, string place);
	void say();
     	void eat(Game & game, Actor * & food);
        void onEverDay(Game & game);
};
//---------------------------------------------------------------------------
#endif