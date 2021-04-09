//-------------------------------------------------------------------------
#ifndef godH
#define godH
//---------------------------------------------
#pragma once

#include "actor.h"

//////////////////…Òœ…////////////////

class God : public Actor
{
public:
	God(string name, bool gender, int power);
	
	void fly();
      	void onWin(Game & game, Actors & losers, Weapons & weapons);
};

//---------------------------------------------------------------------------
#endif