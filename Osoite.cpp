//Osoite.cpp

#include "Osoite.h"
#include <string>
#include <iostream>


//constructors
Osoite::Osoite() : katuOsoite(""), postinumero(""), kunta("")
{
	std::cout << "Luodaan osoite..." << std::endl;
}

Osoite::Osoite(const std::string& a_katuOsoite, const std::string& a_postinumero, const std::string& a_kunta) : katuOsoite(a_katuOsoite), postinumero(a_postinumero), kunta(a_kunta)
{
	std::cout << "Luodaan osoite " << a_katuOsoite << "..." << std::endl;
}


//setters
void Osoite::setKatuosoite(const std::string& a_katuOsoite)
{
	katuOsoite = a_katuOsoite;
}

void Osoite::setPostinumero(const std::string& a_postinumero)
{
	postinumero = a_postinumero;
}

void Osoite::setKunta(const std::string& a_kunta)
{
	kunta = a_kunta;
}


//getters
std::string Osoite::getKatuosoite() const
{
	return katuOsoite;
}

std::string Osoite::getPostinumero() const
{
	return postinumero;
}

std::string Osoite::getKunta() const
{
	return kunta;
}


//Method used for printing the address
void Osoite::tulostaTiedot() const
{
	std::cout << "Osoite: " << katuOsoite << "\n" << postinumero << " " << kunta << std::endl;
}