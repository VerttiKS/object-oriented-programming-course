//Osoite.h

#pragma once
#include <string>

class Osoite
{
public:
	//constructors
	Osoite();
	Osoite(const std::string& a_katuOsoite, const std::string& a_postinumero, const std::string& a_kunta);
	

	//setters
	void setKatuosoite(const std::string& a_katuOsoite);
	void setPostinumero(const std::string& a_postinumero);
	void setKunta(const std::string& a_kunta);


	//getters
	std::string getKatuosoite() const;
	std::string getPostinumero() const;
	std::string getKunta() const;


	//other methods
	void tulostaTiedot() const;
	
private:
	std::string katuOsoite;
	std::string postinumero;
	std::string kunta;
};

