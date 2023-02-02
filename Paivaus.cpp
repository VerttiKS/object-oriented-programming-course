//Paivaus.cpp

#include "Paivaus.h"
#include <iostream>


//Constructor when nothing is inputted
Paivaus::Paivaus() : paiva(0), kk(0), vuosi(0)
{
	std::cout << "Luodaan paivaus..." << std::endl;
}


//Constructor when something is inputted
Paivaus::Paivaus(const int& a_paiva, const int& a_kk, const int& a_vuosi) : paiva(a_paiva), kk(a_kk), vuosi(a_vuosi)
{
	std::cout << "Luodaan paivaus " << a_paiva << "/" << a_kk << "/" << a_vuosi << "..." << std::endl;
}


//Destructor
Paivaus::~Paivaus()
{
	std::cout << "Vapautetaan " << paiva << "/" << kk << "/" << vuosi << " muistista..." << std::endl;
}


//sets
void Paivaus::setPaiva(const int& a_paiva)
{
	paiva = a_paiva;
}


void Paivaus::setKK(const int& a_kk)
{
	kk = a_kk;
}


void Paivaus::setVuosi(const int& a_vuosi)
{
	vuosi = a_vuosi;
}

//gets
int Paivaus::getPaiva() const
{
	return paiva;
}


int Paivaus::getKK() const
{
	return kk;
}


int Paivaus::getVuosi() const
{
	return vuosi;
}



//other methods
void Paivaus::tulostaPaivaus() const
{
	std::cout << "Paivays: " << paiva << "/" << kk << "/" << vuosi << std::endl << std::endl;
}


//other way to insert the date
void Paivaus::syotaPaivaus()
{
	std::cout << "\nSyota paiva: ";
	std::cin >> paiva;

	std::cout << "\nSyota kuukausi: ";
	std::cin >> kk;

	std::cout << "\nSyota vuosi: ";
	std::cin >> vuosi;
}


//Used for adding one day to the date
void Paivaus::paivausPlus()
{
	paiva++;


	//Switch case used for determining if the dates should increase
	switch (kk)
	{
	case 1:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 2:
	{
		if (paiva > 28)
		{
			newMonth();
		}

		break;
	}
	case 3:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 4:
	{
		if (paiva > 30)
		{
			newMonth();
		}

		break;
	}
	case 5:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 6:
	{
		if (paiva > 30)
		{
			newMonth();
		}

		break;
	}
	case 7:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 8:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 9:
	{
		if (paiva > 30)
		{
			newMonth();
		}

		break;
	}
	case 10:
	{
		if (paiva > 31)
		{
			newMonth();
		}

		break;
	}
	case 11:
	{
		if (paiva > 30)
		{
			newMonth();
		}

		break;
	}
	case 12:
	{
		//Here we also go higher
		if (paiva > 31)
		{
			vuosi++;
			paiva = 1;
			kk = 1;
		}

		break;
	} 

	//If the month is not between 1-12, then it's probably 13 and that means we go to the first day of the next year
	default:

		vuosi++;
		paiva = 1;
		kk = 1;

		break;
	}
}

//Sets the day to one and adds a new month
void Paivaus::newMonth()
{
	paiva = 1;
	kk++;
}