//---------------------------------------------------------------------------
#include "monster.h"
#include "game.h"
//---------------------------------------------------------------------------
Monster::Monster(string name, bool gender, int power, string place)
	     :Actor(name,gender,power),_place(place)
{
}
//---------------------------------------------------------------------------
void Monster::say()
{
	Actor::say("Œ“ƒÀ"+ _place + _name + " «“≤......");
}
//---------------------------------------------------------------------------
void Monster::eat(Game & game, Actor * & food)
{
	cout << _name << "≥‘µÙ" << food->getName() << "..." <<endl;
	game.destroyActor(food);
	food = 0;
}
//---------------------------------------------------------------------------
	
	
void Monster::onEverDay(Game & game)
{
	(*this) += 2;
}
//---------------------------------------------------------------------------
