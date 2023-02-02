//Opiskelija.h

#pragma once
#include "Henkilo.h"
#include <string>
#include <vector>
class Opiskelija : public Henkilo
{
public:

	//constructor
	Opiskelija();
	Opiskelija(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite, const std::string& a_opNro);

	//destructor
	~Opiskelija();

	//setters
	void setOpNro(const std::string& a_opNro);
	void setSuoritetutKurssit(const std::vector<std::string>& a_suoritetutKurssit);
	void setOpintopisteet(const int& a_opintopisteet);

	//getters
	std::string getOpNro() const;
	std::vector<std::string> getSuoritetutKurssit() const;
	int getOpintopisteet() const;

	//other methods
	void tulostaTiedot() const;
	void lisaaKurssi(const std::string& kurssi);
	void lisaaOpintopisteita(const int& a_opintopisteet);

private:
	std::string opNro;
	std::vector<std::string> suoritetutKurssit;
	int opintopisteet;
};

