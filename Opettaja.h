//Opettaja.h

#pragma once
#include "Henkilo.h"
#include <string>
#include <vector>
class Opettaja : public Henkilo
{
public:
    //constructors
    Opettaja();
    Opettaja(const std::string& a_Nimi, const int& a_Ika, const Osoite& a_osoite, const std::string& a_koulutusala);

    //destructor
    ~Opettaja();

    //setters
    void setKoulutusala(const std::string& a_koulutusala);
    void setKurssit(const std::vector<std::string>& a_kurssit);

    //getters
    std::string getKoulutusala() const;
    std::vector<std::string> getKurssit() const;

    //other methods
    void tulostaTiedot() const;
    void lisaaKurssi(const std::string& kurssi);
    void poistaKurssi(const std::string& kurssi);

private:
    std::string koulutusala;
    std::vector<std::string> kurssit;
};

