//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
#include "game.h"
#include "gameexcept.h"
//#include "functors.h"

//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
     Game game;
	ifstream file("actors.ini");
	if(!file)
	{
		 cout << "无法打开文件:actors.ini" <<endl;
	   return -1;
	 }

	 try
	 {
	    game.loadActors(file);
	    game.createMonsters(170);
	    game.paly();
	  }

       	  catch (GameException & e)
       	  {
      	  	cout<<endl;
  	        e.report();
	 }

	  cout << endl << "游戏共经历" << game.getDays() << "天........."<<endl;
         system("pause");

	  return 0;
}
//---------------------------------------------------------------------------
 
