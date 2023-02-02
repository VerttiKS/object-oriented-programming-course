//Noppa.cpp

#include "Noppa.h"
#include <iostream>


//Default constructor
Noppa::Noppa() : noppaMaara(1)
{
	std::cout << "Heitetaan noppaa..." << std::endl;
}


//Constructor used for deciding how many dices exist
Noppa::Noppa(const int& a_noppaMaara) : noppaMaara(a_noppaMaara)
{
	if (a_noppaMaara > 5 || 1 > a_noppaMaara)
	{
		//Set the noppaMaara to 1, if there was too many or too little dices
		noppaMaara = 1;
	}
}


//Set the number of dices
void Noppa::setNoppaMaara(const int& a_noppaMaara)
{
	noppaMaara = a_noppaMaara;
}


//Get the number of dices
int Noppa::getNoppaMaara() 
{
	return noppaMaara;
}


//Get the number of the latest dice throw
int Noppa::getViimeisinLukema()
{
	int noppaSumma = 0;

	for (int i = 0; i < noppaMaara; i++)
	{
		noppaSumma = noppaSumma + luku[i];
	}

	return noppaSumma;
}


//Throw a dice
void Noppa::heitaNoppaa()
{
	for (int i = 0; i < noppaMaara; i++)
	{
		std::cout << "Heitetaan noppaa " << i+1 << "..." << std::endl;
		luku[i] = std::rand() % 6 + 1;

		std::cout << "Nopan " << i + 1 << " luvuksi saatiin: " << luku[i] << std::endl << std::endl;
	}
}


//Tell the latest throw
void Noppa::kerroViimeisenHeitonLukema()
{
	int noppaSumma = 0;

	for (int i = 0; i < noppaMaara; i++)
	{
		noppaSumma = noppaSumma + luku[i];
	}

	std::cout << "Viimeisin heitto: " << noppaSumma << ". Heitettyjen noppien maara: " << noppaMaara << std::endl << std::endl;
}
