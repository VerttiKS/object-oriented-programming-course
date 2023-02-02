//Henkilo.cpp
#include "Henkilo.h"
#include "Osoite.h"
#include <iostream>
#include <string>


//Constructor when nothing is inputted
Henkilo::Henkilo() : nimi(""), ika(0)
{
	std::cout << "Luodaan henkilo..." << std::endl;
}


//Constructor when something is inputted
Henkilo::Henkilo(const std::string& a_Nimi, const int& a_Ika) : nimi(a_Nimi), ika(a_Ika)
{
	std::cout << "Luodaan " << a_Nimi << "..." << std::endl;
}


//Constructor when address is also inputted
Henkilo::Henkilo(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite) : nimi(a_Nimi), ika(a_Ika), osoite(a_osoite)
{
	std::cout << "Luodaan " << a_Nimi << "..." << std::endl;
}


//Destructor
Henkilo::~Henkilo()
{
	std::cout << "Vapautetaan " << nimi << " muistista..." << std::endl;
}


//Method used for setting the name
void Henkilo::setNimi(const std::string& a_Nimi)
{
	nimi = a_Nimi;
}


//Method used for setting the age
void Henkilo::setIka(const int& a_Ika)
{
	ika = a_Ika;
}


//Method used for setting the address
void Henkilo::setOsoite(const Osoite& a_osoite)
{
	osoite = a_osoite;
}


//Method used for getting the name
std::string Henkilo::getNimi() const
{
	return nimi;
}


//Method used for getting the age
int Henkilo::getIka() const
{
	return ika;
}


//Method used for getting the address
Osoite Henkilo::getOsoite() const
{
	return osoite;
}


//Method used for printing all info
void Henkilo::tulostaTiedot() const
{
	std::cout << "Nimi: " << nimi << std::endl;

	std::cout << "Ika: " << ika << std::endl;

	osoite.tulostaTiedot();

	std::cout << "\n" << std::endl;
}