//Kalenterimerkinta.h

#pragma once
#include "Paivaus.h"
#include <string>


class Kalenterimerkinta
{
public:
	//constructors
	Kalenterimerkinta();
	Kalenterimerkinta(const Paivaus& a_paivaus, const std::string& a_asia, const bool& a_muistutus);
	Kalenterimerkinta(const Kalenterimerkinta& a_merkinta);

	//Destructor
	~Kalenterimerkinta();


	//setters
	void setPaivaus(const Paivaus& a_paivaus);
	void setAsia(const std::string& a_asia);
	void setMuisoite(const bool& a_muistutus);


	//getters
	Paivaus getPaivaus() const;
	std::string getAsia() const;
	bool getMuistutus() const;


	//other methods
	void tulostaMerkinta() const;
	void kysyTiedot();

private:
	Paivaus paivaus;
	std::string asia;
	bool muistutus;
};

