//--------------------------------------------------------------------

#include "weapon.h"

//--------------------------------------------------------------------
using namespace std;

//--------------------------------------------------------------------
ostream & operator << (ostream & cout, Weapon & weapon)
{
    cout << weapon.getName()<< "(" << weapon.getpower() << ")";
    return cout;
}
//--------------------------------------------------------------------
Weapon::Weapon()
{
}
//--------------------------------------------------------------------
Weapon::Weapon(string name, int power)
      :_name(name), _power(power)
{
}
//--------------------------------------------------------------------
string Weapon::getName()
{
        return _name;
}
//--------------------------------------------------------------------
int Weapon::getpower()
{
      return _power;
}
//-------------------------------------------------------------------
bool Weapon::operator<(const Weapon & other) const
{
   return this -> _power < other._power;
}
//--------------------------------------------------------------------
bool Weapon::operator>(const Weapon & other) const
{
   return this -> _power >other._power;
}

//-------------------------------------------------------------------
