//---------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------
#ifndef weaponH
#define weaponH
//---------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <queue>
//---------------------------------------------------------------------------
using namespace std;

class Weapon
{
private:
       string _name;
       int _power;   //
public:
    Weapon();
    Weapon(string name, int power);


    string getName();
    int getpower();
    bool operator<(const Weapon & other) const;
    bool operator>(const Weapon & other) const;
};

//---------------------------------------------------------------------------
typedef priority_queue<Weapon, vector<Weapon> > Weapons;


ostream & operator << (ostream & cout, Weapon & weapon);
//---------------------------------------------------------------------------
#endif

