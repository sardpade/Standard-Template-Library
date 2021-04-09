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
		 cout << "�޷����ļ�:actors.ini" <<endl;
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

	  cout << endl << "��Ϸ������" << game.getDays() << "��........."<<endl;
         system("pause");

	  return 0;
}
//---------------------------------------------------------------------------
 
