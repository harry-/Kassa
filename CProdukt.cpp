#include "CProdukt.h"

CProdukt::CProdukt()
{
}

CProdukt::~CProdukt()
{
	if (Beschreibung)
		delete[] Beschreibung;
	Beschreibung = nullptr;
	if (Datum)
		delete[] Datum;
	Datum = nullptr;
}


CProdukt::CProdukt(const char * nBeschreibung, const char* nDatum, const unsigned int nPreis)
{
	if (!set_Beschreibung(nBeschreibung))
		std::cerr << "overloaded constructor called with invalid argument\n";
	if (!set_Datum(nDatum))
		std::cerr << "overloaded constructor called with invalid argument\n";
	set_Preis(nPreis);
}

CProdukt::CProdukt(const CProdukt & original)
{
	set_Beschreibung(original.Beschreibung);
	set_Datum(original.Datum);
	set_Preis(original.Preis);
}

CProdukt & CProdukt::operator=(const CProdukt & original)
{
	if (this == &original)
		return *this;

	set_Beschreibung(original.Beschreibung);
	set_Datum(original.Datum);
	set_Preis(original.Preis);

	return *this;
}

bool CProdukt::set_Beschreibung(const char * nBeschreibung)
{
	if (!nBeschreibung)
	{
		std::cerr << "set_Beschreibung called with illegal argument\n";
		return false;
	}

	if (Beschreibung)
	{
		delete[] Beschreibung;
		Beschreibung = nullptr;
	}

	Beschreibung = new char[strlen(nBeschreibung) + 1];

	if (!Beschreibung)
		std::cerr << "memory allocation failed\n";
	else if (copy2(nBeschreibung, Beschreibung))
		return true;

	return false;
}
bool CProdukt::set_Datum(const char * nDatum)
{
	if (!nDatum)
	{
		std::cerr << "set_Datum called with illegal argument\n";
		return false;
	}

	if (Datum)
	{
		delete[] Datum;
		Datum = nullptr;
	}

	Datum = new char[strlen(nDatum) + 1];

	if (!Datum)
		std::cerr << "memory allocation failed\n";
	else if (copy2(nDatum, Datum))
		return true;

	return false;
}

bool CProdukt::set_Preis(const unsigned int nPreis)
{
	Preis = nPreis;
	return true;
}
char * CProdukt::get_Beschreibung()
{
	return Beschreibung;
}
char * CProdukt::get_Datum()
{
	return Datum;
}
unsigned int CProdukt::get_Preis()
{
	return Preis;
}

void CProdukt::display()
{
	std::cout << Beschreibung << ' ' << Datum << ' ' << Preis << '\n';
}
