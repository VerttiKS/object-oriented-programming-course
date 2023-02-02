//Opiskelija.cpp

#include "Opiskelija.h"
#include <iostream>
#include <string>
#include <vector>


//Default constructor
Opiskelija::Opiskelija() : opNro("Ei opiskelijanumeroa")
{
	std::cout << "Luodaan Opiskelija..." << std::endl;
	//Gotta put the opintopisteet to 0 at the start to avoid errors
	opintopisteet = 0;
}


//Constructor with info
Opiskelija::Opiskelija(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite, const std::string& a_opNro) : Henkilo(a_Nimi, a_Ika, a_osoite), opNro(a_opNro)
{
	std::cout << "Luodaan Opiskelija " << a_Nimi << "..." << std::endl;

	//Gotta put the opintopisteet to 0 at the start to avoid errors
	opintopisteet = 0;
}

//Destructor
Opiskelija::~Opiskelija()
{
	std::cout << "Vapautetaan Opiskelija " << getNimi() << " muistista..." << std::endl;
}

//setters
void Opiskelija::setOpNro(const std::string& a_opNro)
{
	opNro = a_opNro;
}

void Opiskelija::setSuoritetutKurssit(const std::vector<std::string>& a_suoritetutKurssit)
{
	suoritetutKurssit = a_suoritetutKurssit;
}

void Opiskelija::setOpintopisteet(const int& a_opintopisteet)
{
	opintopisteet = a_opintopisteet;
}

//getters
std::string Opiskelija::getOpNro() const
{
	return opNro;
}

std::vector<std::string> Opiskelija::getSuoritetutKurssit() const
{
	return suoritetutKurssit;
}


int Opiskelija::getOpintopisteet() const
{
	return opintopisteet;
}



//Method used for printing all info
void Opiskelija::tulostaTiedot() const
{
	std::cout << "----------------------------" << std::endl;

	std::cout << "Opiskelijanumero: " << opNro << std::endl;

	std::cout << "Opiskelija: " << getNimi() << std::endl;

	std::cout << "Ika: " << getIka() << std::endl;

	getOsoite().tulostaTiedot();

	std::cout << "\nSuoritetut kurssit:" << std::endl;
	for (std::string i : suoritetutKurssit)
	{
		std::cout << i << std::endl;
	}

	std::cout << "\nOpintopisteita: " << opintopisteet << "\n" << std::endl;
}

//Adds a new completed course to the course vector
void Opiskelija::lisaaKurssi(const std::string& kurssi)
{
	suoritetutKurssit.push_back(kurssi);
}

//Adds more learningpoints
void Opiskelija::lisaaOpintopisteita(const int& a_opintopisteet)
{
	opintopisteet = opintopisteet + a_opintopisteet;
}