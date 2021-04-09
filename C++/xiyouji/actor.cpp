//------------------------------------------------------------------
#include <functional>
#include <algorithm>
#include "actor.h"
#include "game.h"
//------------------------------------------------------------------
bool comparesActor(Actor * a1, Actor * a2)
{
    return (a1 -> getpower() - a1 -> getWeaponPowers())  >
            (a2 -> getpower() - a2 -> getWeaponPowers());
}
//------------------------------------------------------------------
Actor :: ~Actor()
{
    cout<<_name<<"至此隐退江湖..."<<endl;
}
//------------------------------------------------------------------

//------------------------------------------------------------------
Actor::Actor(string name, bool gender, int power)
      :_name(name), _gender(gender), _power(power)
{
   cout << _name << "出现..." <<endl;
}
//------------------------------------------------------------------
void Actor:: say()
{
    cout << _name << ":我乃" << _name <<"是也..." <<endl;
}
//------------------------------------------------------------------
void Actor:: say(string message)
{
    cout << _name << ":"  <<message<<endl;
}
//------------------------------------------------------------------
Actor & Actor::operator<< (Weapon weapon)
{
     cout << _name << ":兵器+"  << weapon <<endl;
     _weapons.push(weapon);

     return *this;
}
//------------------------------------------------------------------
Actor & Actor::operator>> (Weapon & weapon)
{
     if(!_weapons.empty())
     {
        weapon = _weapons.top();
        cout << _name << ":兵器-"  << weapon <<endl;
        _weapons.pop();
     }
     return *this;
}
//------------------------------------------------------------------
Actor & Actor::operator += (int power)
{
   _power += power;
   return *this;
}
//------------------------------------------------------------------
Actor & Actor::operator -= (int power)
{
    _power -= power;
    if(_power <0 )
        _power =0;

    return * this;
}
//------------------------------------------------------------------
void Actor::onEveryDay(Game & game)
{
}
//------------------------------------------------------------------
void Actor::onLose(Game & game, Actors & winners,Weapons & weapons)
{
   (*this) -= winners.size();
   while(!_weapons.empty() && weapons.size() < winners.size())
   {
        Weapon weapon;
        (*this) >> weapon;

        weapons.push(weapon);
   }

}
//------------------------------------------------------------------
void Actor::onWin(Game & game, Actors & losers, Weapons & weapons)
{
   (*this) += losers.size();
  if(!weapons.empty())
   {
        Weapon weapon = weapons.top();
        (*this) << weapon;

        weapons.pop();
   }
}
//------------------------------------------------------------------
void Actor::onKilled(Game & game, Actors & winners)
{
     game.destroyActor(this);
}

//------------------------------------------------------------------ 
Weapons & Actor::getWeapons (void)
{
  return _weapons;
}
//------------------------------------------------------------------
string Actor::getName(void)
{
  return _name;
}
//------------------------------------------------------------------
int Actor::getpower(void)
{
  return _power;
}
//------------------------------------------------------------------
int Actor::getWeaponPowers(void)
{
  int powers = 0;
  Weapons weapons(_weapons);
  while(!weapons.empty())
  {
     Weapon weapon = weapons.top();
     powers += weapon.getpower();
     weapons.pop();
  }
  return powers;
}
//------------------------------------------------------------------
ostream & operator << (ostream & cout, Actor & actor)
{
     cout<< actor.getName() << "(" << actor.getpower() <<")" ;
     Weapons weapons(actor.getWeapons());
     if(!weapons.empty())
     {
          cout << "[";
          while(!weapons.empty())
          {
             Weapon weapon = weapons.top();
             cout << weapon;
             weapons.pop();
          }
          cout << "]";
     }

     return cout;
}
//------------------------------------------------------------------
