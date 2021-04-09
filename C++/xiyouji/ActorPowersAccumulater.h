//---------------------------------------------------------------------------
#ifndef ActorPowersAccumulaterH
#define ActorPowersAccumulaterH
//---------------------------------------------------------------------------

#pragma once
#include "actor.h"
//---------------------------------------------------------------------------
class ActorPowersAccumulater
{
public:
	int & _powers;
	
	ActorPowersAccumulater(int & powers)
	   : _powers(powers)
	{
		  _powers = 0;
	}
	
	void operator()(Actor * actor)
	{
		 _powers += actor->getPower();
		 _powers += actor->getWeaponPowers();
	}
};
//---------------------------------------------------------------------------
#endif
