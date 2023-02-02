//Opettaja.cpp

#include "Opettaja.h"
#include <iostream>
#include <string>
#include <vector>


//Default constructor
Opettaja::Opettaja() : koulutusala("Ei koulutusalaa")
{
	std::cout << "Luodaan Opettaja..." << std::endl;
}


//constructor
Opettaja::Opettaja(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite, const std::string& a_koulutusala) : Henkilo(a_Nimi, a_Ika, a_osoite), koulutusala(a_koulutusala)
{
	std::cout << "Luodaan Opettaja " << a_Nimi << "..." << std::endl;
}

//destructor
Opettaja::~Opettaja()
{
	std::cout << "Vapautetaan Opettaja " << getNimi() << " muistista..." << std::endl;
}

//setters
void Opettaja::setKoulutusala(const std::string& a_koulutusala)
{
	koulutusala = a_koulutusala;
}

void Opettaja::setKurssit(const std::vector<std::string>& a_kurssit)
{
	kurssit = a_kurssit;
}

//getters
std::string Opettaja::getKoulutusala() const
{
	return koulutusala;
}
std::vector<std::string> Opettaja::getKurssit() const
{
	return kurssit;
}


//Method used for printing all info
void Opettaja::tulostaTiedot() const
{
	std::cout << "----------------------------" << std::endl;

	std::cout << "Opettaja: " << getNimi() << std::endl;

	std::cout << "Ika: " << getIka() << std::endl;

	getOsoite().tulostaTiedot();

	std::cout << "Koulutusala: " << koulutusala << std::endl;

	std::cout << "\nKurssit:" << std::endl;
	for (std::string i : kurssit)
	{
		std::cout << i << std::endl;
	}

	std::cout << "\n" << std::endl;
}


//Method used for adding a course
void Opettaja::lisaaKurssi(const std::string& kurssi)
{
	kurssit.push_back(kurssi);
}


//Method used for removing a course
void Opettaja::poistaKurssi(const std::string& kurssi)
{
	kurssit.erase(std::remove(kurssit.begin(), kurssit.end(), kurssi), kurssit.end());
}