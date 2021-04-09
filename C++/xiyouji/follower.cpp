//---------------------------------------------------------------------------
#include "monster.h"
#include "game.h"
//---------------------------------------------------------------------------
FollowerMonster::FollowerMonster(string name, int power, string place, string newname, string monkName)
	           : Monster(name, true, power, place), _newName(newname), _monkName(monkName)
{
}
//---------------------------------------------------------------------------
void FollowerMonster::onLose(Game & game, Actors & winners, Weapons & weapons)
{
}

//---------------------------------------------------------------------------
void FollowerMonster::onKilled(Game & game, Actors & winners)
{
	stringstream ss;
	ss << this ->_newName << endl << this->_monkName <<endl << this->_power;
	Actor * actor = game.creatActor("monk", ss);
	while(!_weapons.empty())
	{
		(*actor) << _weapons.top();
		_weapons.pop();
	}
	game.joinTravelers(actor);
	game.destroyActor(this);

}
//---------------------------------------------------------------------------
