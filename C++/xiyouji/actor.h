//---------------------------------------------------------------------------
#ifndef actorH
#define actorH
//---------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "weapon.h"
//-------------------------------------------------------------
using namespace std;

//-------------------------------------------------------------

class Game;
class Actor;

typedef vector<Actor *> Actors;

class Actor
{
protected:
    string _name;
    bool _gender;
    int _power;
    Weapons _weapons;

public:
    virtual ~Actor();
    Actor(string name, bool gender, int power);
    virtual Actor & operator<< (Weapon weapon);
    virtual Actor & operator>> (Weapon & weapon);
    virtual void say();
    void say(string message);
    Actor & operator += (int power);
    Actor & operator -= (int power);
    virtual void onEveryDay(Game & game);
    virtual void onLose(Game & game, Actors & winners,Weapons & weapons);
    virtual void onWin(Game & game, Actors & losers, Weapons & weapons);
    virtual void onKilled(Game & game, Actors & winners);
    Weapons & getWeapons (void);
    string getName(void);
    int getpower(void);
    int getWeaponPowers(void);
};
//-------------------------------------------------------------
ostream & operator << (ostream & cout, Actor & actor);
bool comparesActor(Actor * a1, Actor * a2);


//---------------------------------------------------------------------------
#endif
