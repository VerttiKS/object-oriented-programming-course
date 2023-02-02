//Henkilo.h
#pragma once
#include <string>
#include "Osoite.h"

class Henkilo
{
public:

	//constructors
	Henkilo();
	Henkilo(const std::string& a_Nimi, const int& a_Ika);
	Henkilo(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite);

	//destructor
	~Henkilo();

	//setters
	void setNimi(const std::string& a_Nimi);
	void setIka(const int& a_Ika);
	void setOsoite(const Osoite& a_osoite);

	//getters
	std::string getNimi() const;
	int getIka() const;
	Osoite getOsoite() const;

	//other methods
	virtual void tulostaTiedot() const;

protected:
	std::string nimi;
	int ika;
	Osoite osoite;
};

