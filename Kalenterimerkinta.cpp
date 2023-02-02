//Kalenterimerkinta.cpp

#include <iostream>
#include <string>
#include "Kalenterimerkinta.h"


//constructors
Kalenterimerkinta::Kalenterimerkinta() : paivaus(11, 11, 1111), asia(""), muistutus(false)
{

}

Kalenterimerkinta::Kalenterimerkinta(const Paivaus& a_paivaus, const std::string& a_asia, const bool& a_muistutus) : paivaus(a_paivaus), asia(a_asia), muistutus(a_muistutus)
{
	std::cout << "Luodaan merkinta paivaukselle " << paivaus.getPaiva() << "/" << paivaus.getKK() << "/" << paivaus.getVuosi() << "..." << std::endl;
}


Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta& a_merkinta) : asia(a_merkinta.asia), muistutus(a_merkinta.muistutus)
{
	paivaus.syotaPaivaus();
}

//Destructor
Kalenterimerkinta::~Kalenterimerkinta()
{
	std::cout << "Poistetaan merkinta paivauksesta " << paivaus.getPaiva() << "/" << paivaus.getKK() << "/" << paivaus.getVuosi() << "..." << std::endl;
}


//setters
void Kalenterimerkinta::setPaivaus(const Paivaus& a_paivaus)
{
	paivaus = a_paivaus;
}


void Kalenterimerkinta::setAsia(const std::string& a_asia)
{
	asia = a_asia;
}


void Kalenterimerkinta::setMuisoite(const bool& a_muistutus)
{
	muistutus = a_muistutus;
}


//getters
Paivaus Kalenterimerkinta::getPaivaus() const
{
	return paivaus;
}

std::string Kalenterimerkinta::getAsia() const
{
	return asia;
}

bool Kalenterimerkinta::getMuistutus() const
{
	return muistutus;
}


//Method that prints the calender date
void Kalenterimerkinta::tulostaMerkinta() const
{
	std::cout << "Merkinta paivalle: " << paivaus.getPaiva() << "/" << paivaus.getKK() << "/" << paivaus.getVuosi() << "\n";

	std::cout << "Merkinnan aihe: " << asia << "\n" << "Muistutus paalla: ";

	if (muistutus == true)
	{
		std::cout << "On \n" << std::endl;
	}
	else
	{
		std::cout << "Ei ole \n" << std::endl;
	}

}


//Asks for the calender date
void Kalenterimerkinta::kysyTiedot()
{
	paivaus.syotaPaivaus();

	std::cout << "\nSyota aihe: ";
	std::cin >> asia;

	std::cout << "\nLaitetaanko muistutus paalle? Syota 0, jos ei. 1, jos kylla: ";
	std::cin >> muistutus;
}
