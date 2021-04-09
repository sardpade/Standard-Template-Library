//---------------------------------------------------------------------------
#ifndef functorsH
#define functorsH
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
		 _powers += actor->getpower();
		 _powers += actor->getWeaponPowers();
	}
};
//---------------------------------------------------------------------------
#endif
