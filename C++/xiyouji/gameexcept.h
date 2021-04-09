//---------------------------------------------------------------------------
#ifndef gameexcptH
#define gameexcptH
//---------------------------------------------
#pragma once
#include <stdexcept>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
class GameException:public runtime_error
{
public:
	 GameException()
	     : runtime_error("GameException")
	 {
	 }
	 
	 ~GameException() throw()
	 {
	 }
	 
	 virtual void report () = 0;

};
//---------------------------------------------------------------------------
class NosuchType : public GameException
{
private:
	Game & _game;
	string _type;
public:
	NosuchType(Game & game, string type)
	   : _game(game), _type(type)
	{
	}
	
	~NosuchType() throw ()
	{
	}
	
	void report()
	{
		cout << "无法解析指定的类型：" << _type << "!" << endl;
	}
};

//---------------------------------------------------------------------------
class NoActor : public GameException
{
private:
	Game & _game;
	string _name;
public:
	NoActor(Game & game, string name)
	   : _game(game), _name(name)
	{
	}
	
	~NoActor () throw ()
	{
	}
	
	void report()
	{
		cout << "缺少角色：" <<_name << "！" <<endl;
	}
};
//---------------------------------------------------------------------------
class BeKilled : public GameException
{
private:
	Game & _game;
	Actor * _monster;
public:
	BeKilled(Game & game, Actor * monster)
	  : _game(game), _monster(monster)
	{
	}  	
	
	~BeKilled() throw ()
	{
	}

	void report()
	{
		cout << "唐三藏在第" << _game.getLevel() << "回被" << _monster ->getName() <<"吃了！" <<endl;
	}
};
//---------------------------------------------------------------------------
class NoMoreEnemies : public GameException
{
private:
  Game & _game;
public:
	NoMoreEnemies(Game & game)
	  : _game(game)
	{
	}
	
	~NoMoreEnemies() throw ()
	{
	}
	
	void report()
	{
		cout << "在第" << _game.getLevel() << "回已杀光所有敌人！" <<endl;
	}
};
//---------------------------------------------------------------------------
#endif
