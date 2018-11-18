#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <array>

using namespace std ;

class Sistema
{
	public:
		Sistema();
		
	private:
		int answerUser ;
		array < string , 4 > mainMenu ;
		
		void showMenu() ;
};

#endif
