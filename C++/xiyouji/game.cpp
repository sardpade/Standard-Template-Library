//-----------------------------------------------------------------------------
#include "game.h"
#include "gameexcept.h"
#include "functors.h"

#include <ctime>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <functional>

#define LEVELS 81
//-----------------------------------------------------------------------------
////////////////////////外部函数//////////////////
string replace(string & src, string find, string replacement)
{
	 string dest;
	 int i = 0;
	 int len = find.length();
	 
	 while(true)
	 {
	 	   int start = i;
	 	   i = src.find_first_of(find, i );
	    if(i<0)
	    {
	 	      dest += src.substr(start);
	 	      break;
	    }
	  
	    dest += src.substr(start, i - start);
	    dest += replacement;
	    i += len;
	  }
	  return dest;
}


//-----------------------------------------------------------------------------
Game::Game(void)
{
	 cout << "........<<西游记>>开始........" << endl;
}
//-----------------------------------------------------------------------------
Game::~Game(void)
{
	 map<string, Actor *>::iterator it;
	 for(it = _actors.begin(); it != _actors.end(); it++)
	 {
	 	  delete (*it).second;
	 }
	 cout << "........<<西游记>>至此终...." <<endl;
}
//-----------------------------------------------------------------------------
int Game::loadActors(ifstream & actorList)
{
	  Actor * actor = 0;

	  while(!actorList.eof())
	  {
	  	   char line[256];
	  	   actorList.getline(line, 255);
	  	   string s = line;


	  	   if(s.empty())
	  	   	    continue;

	  	   if(s[0] == '#')
	  	   	    continue;

	  	   int i = s.find("=");
	  	   if(i < 0);
	  	   	    //continue;

	  	   string key = s.substr(0, i);
	  	   string value = s.substr(i + 1);

	  	   value = replace(value, ",", "\n");
	  	   stringstream ss (value);

	  	   if(key =="weapon")
	  	   {
	  	   	  string name;
	  	   	  int power;

	  	   	  ss >> name >> power;
	  	   	  Weapon weapon (name, power);
	  	   	  (*actor) << weapon;
	  	   	}

	  	   	else
	  	   	{
	  	   		 actor = creatActor(key, ss);
	  	   	}
	  	}
	  	return _actors.size();
}
//--------------------------------------------------------------------------
Actor * Game::creatActor(string type, stringstream & parameters)
{
	Actor * actor;
	
	if(type == "actor")
	{
		 string name;
		 bool gender;
		 int power;
		 
		 parameters >>name >> boolalpha >> gender >> power;
		 actor = new Actor(name, gender, power);
	}
	
	else if(type =="monk")
	{
		 string name;
		 string monkName;
		 int power;
		 
		 parameters >>name >>  monkName >> power;
		 actor = new Monk(name, monkName, power);
	 }
	 
	 else if(type == "god")
	 {
	 	 string name;
		 bool gender;
		 int power;
		 
		 parameters >>name >> boolalpha >> gender >> power;
		 actor = new God(name, gender, power);
	  }
	  
	  else if(type == "monster")
	 {
	 	 string name;
		 bool gender;		
		 int power;
		 string place;
		 
		 
		 parameters >>name >> boolalpha >> gender >> power >> place;
		 actor = new Monster(name, gender, power, place);
	  }
	  
	   else if(type == "follower")
	 {
	 	 string name;	
		 int power;
		 string place;
		 string newName;
		 string monkName;
		 
		 
		 parameters >>name >> power >> place >> newName >> monkName;
		 actor = new FollowerMonster(name, power, place, newName, monkName);
	  }
	  
	  else
	  {
	  	throw NosuchType(*this, type);
	  }
	  
	  _actors[ actor->getName()] = actor;
	  return actor;

}
//-----------------------------------------------------------------------------
void Game::destroyActor(Actor * actor)
{
	 map<string, Actor*>::iterator it = _actors.find(actor->getName());
	 if(it != _actors.end())
	 	   _actors.erase(it);
	 
	Actors::iterator ita = find(_travelers.begin(), _travelers.end(), actor);
	 
	 if(ita != _travelers.end())
	 {
	 	  iter_swap(ita, _travelers.end() -1);
	 	  _travelers.pop_back();
	 }
	  delete actor;
}
//-----------------------------------------------------------------------------
void Game::paly(void)
{
	 srand(time(0));
	 _level = 0;
	 _days = 0;
	 _monkTang = 0;

	_travelers.clear();
	 if(_actors.find("唐三藏") == _actors.end())
	 {
	 	 throw NoActor(*this, "唐三藏");
	 }
	 
	  if(_actors.find("孙悟空") == _actors.end())
	 {
	 	 throw NoActor(*this, "孙悟空");
	 }
	 	
	 _monkTang = _actors["唐三藏"];
	 _travelers.push_back(_monkTang);
	 _travelers.push_back(_actors["孙悟空"]);
	 
	 for(int i = 1; i <= LEVELS; i++)
	 {
	 	  cout<<endl<< "-----第" << i << "回-----" <<endl <<endl;
	 	  paly(i);
	 }
}


//-----------------------------------------------------------------------------
void Game::build(Actors & monks, Actors & enemies, Actors & gods)
{
	  Actors monsters;
	  gods.clear();
	  
	  map<string, Actor *>::iterator it;
	  for(it=_actors.begin();it!=_actors.end();it++)
	  {
	  	Actor*actor=(*it).second;
	  	
	  	if(isGod(*actor))
	  	{
	  		 gods.push_back(actor);
	  	}
	  	
	  	if(isMonster(*actor))
	  	{
	  		 monsters.push_back(actor);
	  	}
	  }
	  
	  if(monsters.empty())
	  	  throw NoMoreEnemies(*this);
	  	  
	 buildEnemies(monsters,enemies);

}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Game::paly(int level)
{
    _level = level;
    
    Actors gods;
    Actors monks(_travelers);
    Actors enemies;
    build(monks, enemies, gods);
    
    int days = captureTang(enemies, monks);
    
    bool ok = false;
   	for(int i = 0; i < days ; i++)
   	{
   	   _days++;
   	   cout << endl << "-----第" << (i + 1) << "天-----" <<endl;

   	   map<string, Actor *>::iterator it;
   	   for(it = _actors.begin(); it != _actors.end(); it++)
   	   {
   	   	  Actor * actor = (*it).second;
   	   	  actor->onEveryDay(*this);
   	   }

   	   int delta = fight(monks, enemies);
   	   if(delta < 150)
   	   {
   	   	cout << "交战失败，未能解救唐三藏!" <<endl;

   	   	win(enemies, monks);
   	   	cout << "求助神仙...." <<endl;
   	   	if(!askForHelp(monks, gods))
   	   	{
   	   		 cout << "没有神仙可求的了,闯关失败...." <<endl;
   	   		 break;
   	   	}
   	    }
           
   		
   		else
   		{
   			 cout << "大获全胜，成功解救唐三藏！" <<endl;
   			 
   			 win(monks, enemies);
   			 
   			 if(delta < 170)
   			 {
   			 	  cout << "敌方成功逃脱！" <<endl;
   			 	  escape(monks, enemies);
   			 }
   			 else
   			 {
   			 	  cout << "敌方被全部消灭！" <<endl;
   			 	  kill(monks, enemies);
   			 }
   			 ok = true;
   			 break;
   		 }
                 }
                 
        if(!ok)
        {
        	 cout << endl <<days << "天期限已过" <<endl;
        	 Actor * actor = enemies[ rand()% enemies.size()];
        	 ((Monster *)actor)->eat(*this, _monkTang);
        	 throw BeKilled(*this, actor);
        }
           cout << endl;
           printActors("取经团队", _travelers);
}

//-----------------------------------------------------------------------------
void Game::printActors(string title, Actors & actors)
{
	 cout << "[" << title << "]" <<endl;

	 Actors::iterator it;
	 for(it = actors.begin(); it != actors.end(); it++)
	 {
	 	  Actor & actor = *(*it);
	 	  cout << actor << endl;
	 }
	 cout <<endl;
}
//-----------------------------------------------------------------------------
bool Game::isMonster(Actor & actor)
{
	 if(typeid(actor) == typeid(Monster))
	 	 return true;
	 	 
	 if(typeid(actor) == typeid(FollowerMonster))
	 	 return true;
	 	 
	 	return false;
}
//-----------------------------------------------------------------------------
bool Game::isGod(Actor & actor)
{
	 if(typeid(actor) == typeid(God))
	 	 return true;
	 	 
	 	return false;
}
//-----------------------------------------------------------------------------
void Game::joinTravelers(Actor * actor)
{
	  cout << actor->getName() << "加入取经行列...." <<endl;
	  _travelers.push_back(actor);
}
//-----------------------------------------------------------------------------
int Game::captureTang (Actors & enemies, Actors & monks)
{
	  Actors::iterator it = find(monks.begin(), monks.end(), _monkTang);
	  if(it == monks.end())
	      throw NoActor(*this, "唐三藏");
	  
	  int days = 3 + rand() % 8;
	  cout << "妖怪抓住唐三藏，限期" <<days << "天...." <<endl	;
	  
	  iter_swap(it, monks.end() -1);
	  monks.pop_back();
	  
	  return days;
	  
}
//-----------------------------------------------------------------------------
int Game::getLevel(void)
{
	  return _level;
}
//-----------------------------------------------------------------------------
int Game::getDays(void)
{
	  return _days;
}
//-----------------------------------------------------------------------------
void Game::escape(Actors & winners, Actors & losers)
{

}
//-----------------------------------------------------------------------------
void Game::kill(Actors & winners, Actors & losers)
{
	  Actors::iterator it;
	  for(it = losers.begin(); it != losers.end(); it++)
	  {
	  	 Actor * actor = *it;
	  	 actor->onKilled(*this, winners);
	  }
	  losers.clear();
}
//-----------------------------------------------------------------------------
void Game::win(Actors & winners, Actors & losers)
{
	  Weapons weapons;
	  
	  Actors::iterator it;
	 for(it = losers.begin(); it != losers.end(); it++)
	 {
	 	 Actor & actor = *(*it);
	 	 actor.onLose(*this, winners, weapons);
	 }
	 	
	 Actors winners2(winners);
	 sort(winners2.begin(), winners2.end(), comparesActor);
	 
	 for(it = winners2.begin(); it !=winners2.end(); it++)
	 {
	 	 Actor & actor = *(*it);
	 	 actor.onWin(*this, losers, weapons);
	 }
	 
}
//-----------------------------------------------------------------------------
int Game::fight(Actors & monks, Actors & enemies)
{
	  cout << "营救唐三藏.....双方交战中...." <<endl <<endl;
	  
	  printActors("我方", monks);
	  printActors("敌方", enemies);
	  
	  int powers1, powers2;
	  
	  ActorPowersAccumulater pal(powers1);
	  for_each(monks.begin(), monks.end(), pal);

	  ActorPowersAccumulater pa2(powers2);
	  for_each(enemies.begin(), enemies.end(), pa2);
	  
	  return powers1 - powers2;
}
//-----------------------------------------------------------------------------
bool Game::askForHelp(Actors & monks, Actors & gods)
{
	  if(gods.empty())

	  	return false;
	  	
	  int selected = rand() %gods.size();
	  Actor * god = gods[selected];
	  cout <<god->getName()<<"加入我方......"<<endl;

	  iter_swap(gods.begin() + selected, gods.end()- 1);
	  gods.pop_back();
	  monks.push_back(god);
	  return true;

}
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
void Game::buildEnemies(Actors & monsters, Actors & enemies)
{
	  enemies.clear();
	  
	  int count = 1+rand()%4;
	  
	  for(int i = 0; i<count; i++)
	  {
	      if(monsters.empty())
	      	break;
	   int selected = rand() % monsters.size();
	   Actor * & monster = monsters[selected];
	   monster->say();
	   
	   enemies.push_back(monster);
	   
	   iter_swap(monsters.begin() + selected, monsters.end() - 1);
	   monsters.pop_back();
	  }

}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Game::createMonsters(int count)
{
    for(int i = 0; i < count; i++)
    {
       stringstream ss;
       ss<<"无名小妖"<<i<<endl<<
          (rand()%2 ? "true" : "false")<<endl<<
          (10 +rand()%10) <<endl<<i<<"号洞穴";
       
       Actor * actor = creatActor("monster", ss);
       ostringstream oss;
       oss<<"无名兵器"<<i;
       
       Weapon weapon (oss.str(), 10 + rand() %10)	;
       (*actor) << weapon;
     }
}
//-----------------------------------------------------------------------------





