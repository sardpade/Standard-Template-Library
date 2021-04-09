//-----------------------------------------------------------------------------
#ifndef gameH
#define gameH
//---------------------------------------------
#pragma once

#include "actor.h"
#include "monk.h"
#include "god.h"
#include "follower.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
//-----------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------
///////////////////Íâ²¿º¯Êý/////////////////
string replace(string & src, string find, string replacement);
///////////////////Game////////////////////
class Game
{
private:
	int _level;
	int _days;
	map<string, Actor *> _actors;
	Actors _travelers;
	Actor * _monkTang;
	void printActors(string title, Actors & actors);
	void buildEnemies(Actors & monsters, Actors & enemies);
	void build(Actors & monks, Actors & enemies, Actors & gods);
	bool isGod(Actor & actor);
	bool isMonster(Actor & actor);
	int captureTang (Actors & enemies, Actors & monks);
	void escape(Actors & winners, Actors & losers);
	void kill(Actors & winners, Actors & losers);
	int fight(Actors & monks, Actors & enemies);
	bool askForHelp(Actors & monks, Actors & gods);
	void win(Actors & winners, Actors & losers);
public:
	Game(void);
	~Game(void);
	int loadActors(ifstream & actorList);
	Actor * creatActor(string type, stringstream & parameters);
	void destroyActor(Actor * actor);
	void paly(void);
	void paly(int level);
	int getLevel(void);
	int getDays(void);
	void createMonsters(int count);
	void joinTravelers(Actor * actor);
};
//---------------------------------------------------------------------------
#endif
