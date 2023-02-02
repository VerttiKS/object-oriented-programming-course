//Koulu.cpp

#include "Koulu.h"
#include "Opiskelija.h"
#include "Opettaja.h"
#include <iostream>
#include <string>
#include <vector>


//constructors
Koulu::Koulu() : koulunNimi("")
{
	std::cout << "Luodaan nimeton koulu..." << std::endl;
}


Koulu::Koulu(const std::string &a_koulunNimi) : koulunNimi(a_koulunNimi)
{
	std::cout << "Luodaan koulu " + a_koulunNimi + "..." << std::endl;
}


//destructor
Koulu::~Koulu()
{
	std::cout << "Vapautetaan koulu " + koulunNimi + " muistista..." << std::endl;

	for (Opiskelija* h : opiskelijat)
	{
		delete h;
	}

	for (Opettaja* h : opettajat)
	{
		delete h;
	}

	std::cout << "Koulu " + koulunNimi + " vapautettu muistista!" << std::endl;
}


//setters
void Koulu::setOpiskelijat(const std::vector<Opiskelija*> &a_opiskelijat)
{
	opiskelijat = a_opiskelijat;
}


void Koulu::setOpettajat(const std::vector<Opettaja*> &a_opettajat)
{
	opettajat = a_opettajat;
}


void Koulu::setKoulunNimi(const std::string &a_koulunNimi)
{
	koulunNimi = a_koulunNimi;
}


//getters
std::vector<Opiskelija*> Koulu::getOpiskelijat() const
{
	return opiskelijat;
}

std::vector<Opettaja*> Koulu::getOpettajat() const
{
	return opettajat;
}

std::string Koulu::getKoulunNimi() const
{
	return koulunNimi;
}


//Adds a new student
void Koulu::lisaaOpiskelija()
{
	std::string name;
	int age;
	std::string road;
	std::string postalCode;
	std::string city;
	std::string opNum;


	std::cout << "\n\nSyota nimi: ";
	std::getline(std::cin, name);

	std::cout << "Syota ika: ";
	std::cin >> age;
	std::cin.ignore();

	std::cout << "Syota katu: ";
	std::getline(std::cin, road);

	std::cout << "Syota postinumero: ";
	std::getline(std::cin, postalCode);

	std::cout << "Syota kaupunki: ";
	std::getline(std::cin, city);

	std::cout << "Syota opiskelijanumero: ";
	std::getline(std::cin, opNum);

	opiskelijat.push_back(new Opiskelija(name, age, Osoite(road, postalCode, city), opNum));
}


//Adds a new teacher
void Koulu::lisaaOpettaja()
{
	std::string name;
	int age;
	std::string road;
	std::string postalCode;
	std::string city;
	std::string career;

	std::cout << "Syota nimi: ";
	std::getline(std::cin, name);

	std::cout << "Syota ika: ";
	std::cin >> age;
	std::cin.ignore();

	std::cout << "Syota katu: ";
	std::getline(std::cin, road);

	std::cout << "Syota postinumero: ";
	std::getline(std::cin, postalCode);

	std::cout << "Syota kaupunki: ";
	std::getline(std::cin, city);

	std::cout << "Syota koulutusala: ";
	std::getline(std::cin, career);

	opettajat.push_back(new Opettaja(name, age, Osoite(road, postalCode, city), career));
}


//Prints all the information
void Koulu::tulostaKaikkiTiedot()
{
	std::cout << "Koulun nimi: " << koulunNimi << "\nOpettajia: " << opettajat.size() << "\nOpiskelijoita: " << opiskelijat.size() << std::endl;

	tulostaOpettajat();

	std::cout << "\n" << std::endl;

	tulostaOpiskelijat();
}


//Prints student information
void Koulu::tulostaOpiskelijat()
{
	std::cout << "Opiskelijat:" << std::endl;

	for (Opiskelija* h : opiskelijat)
	{
		h->tulostaTiedot();
	}
}


//Prints teacher information
void Koulu::tulostaOpettajat()
{
	std::cout << "Opettajat:" << std::endl;

	for (Opettaja* h : opettajat)
	{
		h->tulostaTiedot();
	}
}
