//Koulu.h

#pragma once

#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
#include <vector>

class Koulu
{
public:
	//constructors
	Koulu();
	Koulu(const std::string &a_koulunNimi);

	//destructor
	~Koulu();

	//setters
	void setOpiskelijat(const std::vector<Opiskelija*> &a_opiskelijat);
	void setOpettajat(const std::vector<Opettaja*> &a_opettajat);
	void setKoulunNimi(const std::string &a_koulunNimi);

	//getters
	std::vector<Opiskelija*> getOpiskelijat() const;
	std::vector<Opettaja*> getOpettajat() const;
	std::string getKoulunNimi() const;

	//other methods
	void lisaaOpiskelija();
	void lisaaOpettaja();
	void tulostaKaikkiTiedot();
	void tulostaOpiskelijat();
	void tulostaOpettajat();

private:
	std::vector<Opiskelija*> opiskelijat;
	std::vector<Opettaja*> opettajat;
	std::string koulunNimi;
};

