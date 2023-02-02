//Noppa.h

#pragma once
class Noppa
{
public:
	//constructors
	Noppa();
	Noppa(const int& a_noppaMaara);

	//setters
	void setNoppaMaara(const int& a_noppaMaara);

	//getters
	int getNoppaMaara();
	int getViimeisinLukema();

	//other methods
	void heitaNoppaa();
	void kerroViimeisenHeitonLukema();

private:
	//Dices
	int luku[5];

	//Amount of dices
	int noppaMaara;
};

