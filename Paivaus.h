//Paivaus.h

#pragma once
class Paivaus
{
public:
	//constructors
	Paivaus();
	Paivaus(const int& a_paiva, const int& a_kk, const int& a_vuosi);

	//destructor
	~Paivaus();

	//setters
	void setPaiva(const int& a_paiva);
	void setKK(const int& a_kk);
	void setVuosi(const int& a_vuosi);

	//getters
	int getPaiva() const;
	int getKK() const;
	int getVuosi() const;

	//other methods
	void tulostaPaivaus() const;
	void syotaPaivaus();
	void paivausPlus();

private:
	int paiva;
	int kk;
	int vuosi;

	void newMonth();
};

