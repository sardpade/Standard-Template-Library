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
		cout << "�޷�����ָ�������ͣ�" << _type << "!" << endl;
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
		cout << "ȱ�ٽ�ɫ��" <<_name << "��" <<endl;
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
		cout << "�������ڵ�" << _game.getLevel() << "�ر�" << _monster ->getName() <<"���ˣ�" <<endl;
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
		cout << "�ڵ�" << _game.getLevel() << "����ɱ�����е��ˣ�" <<endl;
	}
};
//---------------------------------------------------------------------------
#endif
