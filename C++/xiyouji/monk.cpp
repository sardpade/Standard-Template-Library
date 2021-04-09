//---------------------------------------------------------------------------
#include "monk.h"

//---------------------------------------------------------------------------
Monk::Monk(string name, string monkName, int power)
      :Actor(name,true,power),_monkName(monkName)
{
	
}
//---------------------------------------------------------------------------
Monk::~Monk()
{
	 Actor::say("∞¢√÷Õ”ÅÆ£¨∆∂…Æ»•“≤....");
}
//---------------------------------------------------------------------------
void Monk::say()
{
	 Actor::say("∞¢√÷Õ”ÅÆ£¨∆∂…ÆƒÀ"+ _monkName + " «“≤....");
}
//---------------------------------------------------------------------------
void Monk::patter()
{
	 cout<< _name <<"£∫ÜÜ¬Ôƒÿ∞»ﬂ‰ÖÀ...."<<endl;
}
//---------------------------------------------------------------------------
	
string Monk::getName()
{
	return _name;
}
//---------------------------------------------------------------------------
Actor &  Monk::operator>> (Weapon & weapon)
{
	if(_weapons.empty())
	{
		cout << _name <<":±¯∆˜£´"<< weapon <<endl;
	}
	return * this;
}
//---------------------------------------------------------------------------
void Monk::onWin(Game & game, Actors & losers, Weapons & weapons)
{
	(*this) += losers.size();
	
	if(!weapons.empty())
		{
			Weapon weapon = weapons.top();
			
			if(_weapons.empty())
				{
					(*this) << weapon;
					weapons.pop();
				}
				
			else
				{
					Weapon mine = _weapons.top();
					if(mine < weapon)
						{
							(*this) >> mine;
							weapons.pop();
							weapons.push(mine);
							(*this) << weapon;
						}
					}
			}
}
//--------------------------------------------------------------------------- 
