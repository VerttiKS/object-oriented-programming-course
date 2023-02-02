//main.cpp

//-----------------------------------
//Libraries

#include <iostream>
#include <string>
#include <vector>


//-----------------------------------
//classes

#include "Paivaus.h"
#include "Henkilo.h"
#include "Noppa.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include "Koulu.h"


//---------------------
//Functions

void HenkiloCode(); 
void PaivausCode();
void TulostusTest();
void ThrowDice();
void Arvoparametri(Kalenterimerkinta);
void Viittausparametri(const Kalenterimerkinta&);
void HenkiloLoop();
void HenkiloLoopBetter();
void OpiskelijaOpettajaHenkiloLoop();
void OpiskelijaOpettajaCode();
void KouluLoop();


int main()
{
	KouluLoop();

	return 0;
}

//Simulation of a school
void KouluLoop()
{
	int answer = 0;
	std::string schoolName;

	std::cout << "Anna koululle nimi: ";
	std::getline(std::cin, schoolName);

	Koulu koulu(schoolName);


	//While loop where we create new people
	while (true)
	{
		std::cout << "\n\nTee valinta syottamalla luku \n1. Lisaa uusi opettaja \n2. Lisaa opettajalle kurssi \n3. Lisaa uusi opiskelija \n4. Lisaa opiskelijalle kurssi \n5. Tulosta opettajat \n6. Tulosta opiskelijat \n7. Tulosta koulun tiedot \n8. Lopeta \n\nSyota luku: ";
		std::cin >> answer;
		std::cin.ignore();

		switch (answer)
		{

		//Create new teacher
		case 1:
		{
			koulu.lisaaOpettaja();
			break;
		}

		//Add a new course for teacher
		case 2:
		{
			std::string name;
			std::string course;


			//Ask for the teacher name and course name
			std::cout << "Olet antamassa opettajalle uutta kurssia.\nAnna opettajan nimi: ";
			std::getline(std::cin, name);

			std::cout << "Anna kurssin nimi: ";
			std::getline(std::cin, course);


			for (Opettaja* h : koulu.getOpettajat())
			{
				//Give the teacher the course
				if (h->getNimi() == name)
				{
					h->lisaaKurssi(course);
				}
			}
			break;
		}

		//Create new student
		case 3:
		{
			koulu.lisaaOpiskelija();
			break;
		}

		//Print out all the people
		case 4:
		{
			std::string name;
			std::string course;


			//Ask for the student name and course name
			std::cout << "Olet antamassa opiskelijalle uutta kurssia.\nAnna opiskelijan nimi: ";
			std::getline(std::cin, name);

			std::cout << "Anna kurssin nimi: ";
			std::getline(std::cin, course);


			for (Opiskelija* h : koulu.getOpiskelijat())
			{
				//Give the teacher the course
				if (h->getNimi() == name)
				{
					h->lisaaKurssi(course);
				}
			}
			break;
		}

		//Print teachers
		case 5:
		{
			koulu.tulostaOpettajat();
			break;
		}

		//Print students
		case 6:
		{
			koulu.tulostaOpiskelijat();
			break;
		}

		//Create new teacher
		case 7:
		{
			koulu.tulostaKaikkiTiedot();
			break;
		}

			//Leave
		default:
		{
			return;
		}

		}
	}
}


//Used for testing the Opiskelija and Opettaja classes
void OpiskelijaOpettajaCode()
{
	Opettaja TyhjaOpe;
	Opettaja Matti("Matti", 31, Osoite("Karkkikatu 4", "34200", "Hopola"), "Matematiikka");

	Opiskelija TyhjaOpis;
	Opiskelija Pate("Pate", 31, Osoite("Kuppikatu 2", "34200", "Hopola"), "ON340923");
	

	Pate.lisaaKurssi("Matematiikan ihmeet");

	Opiskelija PateKlooni(Pate);
	PateKlooni.setNimi("PateKlooni");

	Pate.lisaaKurssi("Tietotekniikka");

	Pate.lisaaOpintopisteita(23);


	//Compare Pates
	TyhjaOpis.tulostaTiedot();

	Pate.tulostaTiedot();

	PateKlooni.tulostaTiedot();


	Matti.lisaaKurssi("Matematiikan ihmeet");
	Matti.lisaaKurssi("Tietotekniikka");

	Opettaja MattiKlooni(Matti);
	MattiKlooni.setNimi("MattiKlooni");

	Matti.poistaKurssi("Tietotekniikka");


	//Compare Matties
	TyhjaOpe.tulostaTiedot();

	Matti.tulostaTiedot();

	MattiKlooni.tulostaTiedot();

	return;
}

//Used for creating Opiskelijat, Opettajat and Henkilot in a vector
void OpiskelijaOpettajaHenkiloLoop()
{
	std::vector<Henkilo*> henkiloita;

	int answer = 0;

	std::string name;
	int age;
	std::string road;
	std::string postalCode;
	std::string city;
	std::string extraInfo;


	//While loop where we create new people
	while (true)
	{
		std::cout << "\n\nTee valinta syottamalla luku \n1. Lisaa uusi henkilo \n2. Lisaa uusi oppilas \n3. Lisaa uusi opettaja \n4. Tulosta henkilot \n5. Lopeta \n\nSyota luku: ";
		std::cin >> answer;
		std::cin.ignore();

		switch (answer)
		{
			//Create new person
		case 1:
		{
			std::cout << "\n\nSyota nimi: ";
			std::getline(std::cin, name);

			std::cout << "Syota ika: ";
			std::cin >> age;
			std::cin.ignore();

			henkiloita.push_back(new Henkilo(name, age));

			break;
		}

		//Create new student
		case 2:
		{
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
			std::getline(std::cin, extraInfo);

			henkiloita.push_back(new Opiskelija(name, age, Osoite(road, postalCode, city), extraInfo));

			break;
		}

		//Create new teacher
		case 3:
		{
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
			std::getline(std::cin, extraInfo);

			henkiloita.push_back(new Opettaja(name, age, Osoite(road, postalCode, city), extraInfo));

			break;
		}

		//Print out all the people
		case 4:
		{

			for (Henkilo* h : henkiloita)
			{
				h->tulostaTiedot();
			}

			break;
		}

		//Manually delete everything and then return
		default:
		{
			for (Henkilo* h : henkiloita)
			{
				delete h;
			}

			return;
		}

		}
	}

}

//Used for creating new people in a vector in a better way
void HenkiloLoopBetter()
{
	std::vector<Henkilo*> henkiloita;

	int answer = 0;

	std::string name;
	int age;


	//While loop where we create new people
	while (true)
	{
		std::cout << "\n\nTee valinta syottamalla luku \n1. Lisaa uusi henkilo \n2. Tulosta henkilot \n3. Lopeta \n\nSyota luku: ";
		std::cin >> answer;
		std::cin.ignore();

		switch (answer)
		{
			//Create new person
		case 1:
		{
			std::cout << "\n\nSyota nimi: ";
			std::getline(std::cin, name);

			std::cout << "Syota ika: ";
			std::cin >> age;
			std::cin.ignore();

			henkiloita.push_back(new Henkilo(name, age));

			break;
		}

		//Print out all the people
		case 2:
		{

			for (Henkilo* h : henkiloita)
			{
				h->tulostaTiedot();
			}

			break;
		}

		//Manually delete everything and then return
		default:
		{
			for (Henkilo* h : henkiloita)
			{
				delete h;
			}

			return;
		}

		}
	}

}

//Used for creating new people in a vector
void HenkiloLoop()
{
	std::vector<Henkilo> henkiloita;

	int answer = 0;

	std::string name;
	int age;


	//While loop where we create new people
	while (true)
	{
		std::cout << "\n\nTee valinta syottamalla luku \n1. Lisaa uusi henkilo \n2. Tulosta henkilot \n3. Lopeta \n\nSyota luku: ";
		std::cin >> answer;
		std::cin.ignore();

		switch (answer)
		{
			//Create new person
			case 1:
			{
				std::cout << "\n\nSyota nimi: ";
				std::getline(std::cin, name);

				std::cout << "Syota ika: ";
				std::cin >> age;
				std::cin.ignore();
				
				henkiloita.push_back(Henkilo(name, age));

				break;
			}

			//Print out all the people
			case 2:
			{

				for (Henkilo h : henkiloita)
				{
					h.tulostaTiedot();
				}

				break;
			}

			//Leave and delete all the people
			default:
			{
				return;
			}
			
		}
	}
	
}

//used for testing copying in a bad way
void Arvoparametri(Kalenterimerkinta i)
{
	i.tulostaMerkinta();
}

//used for testing copying in a good way
void Viittausparametri(const Kalenterimerkinta& i)
{
	i.tulostaMerkinta();
}

//Used when running the henkilo class by itself
void HenkiloCode()
{
	Henkilo Pate("Pate", 31, Osoite("Kuppikatu 2", "34200", "Hopola"));

	Henkilo Matti("Matti", 22);
	Matti.setOsoite(Osoite("Kanikatu 4", "49300", "Hessula"));

	Pate.tulostaTiedot();

	Matti.tulostaTiedot();

	return;
}


//Used when running the Paivausclass by itself
void PaivausCode()
{
	//Set up everything

	Paivaus tanaan(17, 3, 2022);
	Paivaus huomenna(18, 3, 2022);
	Paivaus omaPaivaus;

	omaPaivaus.syotaPaivaus();

	//One way of printing
	std::cout << "------------------" << std::endl;
	std::cout << "Tulostus:" << std::endl << std::endl;

	std::cout << "Paivaus: " << tanaan.getPaiva() << "/" << tanaan.getKK() << "/" << tanaan.getVuosi() << std::endl;


	//Other way of printing
	huomenna.tulostaPaivaus();

	omaPaivaus.tulostaPaivaus();


	//Print omaPaivaus after adding a date to it
	omaPaivaus.paivausPlus();

	omaPaivaus.tulostaPaivaus();

	return;
}


//Function used for testing the construcors and destuctors
void TulostusTest()
{
	//Create at start test
	std::cout << "Alussa luotu:" << std::endl;

	Henkilo Toni("Toni", 51);
	Henkilo Teppo("Teppo", 29);


	//If test
	std::cout << std::endl << "If lauseessa luotu:" << std::endl;

	if (true)
	{
		Paivaus paiva(24, 3, 2022);
		paiva.tulostaPaivaus();
	}


	//For loop test
	std::cout << std::endl << "For loopissa luotu:" << std::endl;

	for (int i = 0; i < 1; i++)
	{
		Henkilo* Aku = new Henkilo("Aku", 27);

		//Aku must be deleted manually, because he is a new Henkilo and doesn't get deleted automatically
		delete Aku;
	}


	//Function test
	std::cout << std::endl << "Aliohjelmassa luotu:" << std::endl;

	HenkiloCode();


	//Declaring the the program will now end
	std::cout << std::endl << "Ohjelma loppuu nyt. Taman jalkeen vapautetut nimet poistettiin lopussa" << std::endl;

	return;
}


//Throws the dice
void ThrowDice()
{
	//Do the srand, so the random works
	srand(time(NULL));


	//Create dices
	Noppa dicegame(3);

	//throw the dices
	dicegame.heitaNoppaa();

	//print the dices
	dicegame.kerroViimeisenHeitonLukema();


	//Change the dices to five dices
	dicegame.setNoppaMaara(5);

	//Test get
	std::cout << "Noppien maara muutettiin maaraan: " << dicegame.getNoppaMaara() << std::endl << std::endl;

	//throw the dices
	dicegame.heitaNoppaa();

	//print the dices
	dicegame.kerroViimeisenHeitonLukema();


	return;
}