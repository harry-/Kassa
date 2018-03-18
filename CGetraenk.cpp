#include "CGetraenk.h"



CGetraenk::CGetraenk()
{
}

CGetraenk::~CGetraenk()
{
	delete[] Name; //todo die anderen Arrays werden im base destructor geloescht?
}

CGetraenk::CGetraenk(const char * nBeschreibung, const char * nDatum, const unsigned int nPreis, const char * nName, const unsigned short nKategorie, const unsigned short nAlkoholgehalt) 
	:CProdukt(nBeschreibung, nDatum, nPreis)
{
	setName(nName);
	setKategorie(nKategorie);
	setAlkoholgehalt(nAlkoholgehalt);
}

CGetraenk::CGetraenk(CGetraenk & original) : CProdukt(original)
{
	setName(original.Name);
	setKategorie(original.Kategorie);
	setAlkoholgehalt(original.Alkoholgehalt);
}

CGetraenk::CGetraenk(CGetraenk && original)
{
	Name = original.Name;
	original.Name = nullptr;
	Kategorie = original.Kategorie;
	original.Kategorie = '-';
	Alkoholgehalt = original.Alkoholgehalt;
	original.Alkoholgehalt = 0;
}

CGetraenk & CGetraenk::operator=(CGetraenk & original)
{
	CProdukt::operator=(original);
	setName(original.Name);
	setKategorie(original.Kategorie);
	setAlkoholgehalt(original.Alkoholgehalt);
	return *this;
}

CGetraenk & CGetraenk::operator=(CGetraenk && original)
{
	CProdukt::operator=(original);
	Name = (original.Name);
	original.Name = nullptr;
	Kategorie = (original.Kategorie);
	original.Kategorie = '-';
	Alkoholgehalt = (original.Alkoholgehalt);
	original.Alkoholgehalt = 0;
	return *this;
}

bool CGetraenk::setName(const char * nName)
{
	if (!nName)
		return false;
	if (Name)
	{
		delete[] Name;
		Name = nullptr;
	}

	Name = new char[strlen(nName) + 1];
	if (Name)
	{
		copy2(nName, Name);
		return true;
	}
	else
	{
		std::cerr << "memory allocation failed";
		return false;
	}
}

bool CGetraenk::setKategorie(const char nKategorie)
{
	Kategorie = nKategorie;
	return true;
}

bool CGetraenk::setAlkoholgehalt(const unsigned short nAlkoholgehalt)
{
	Alkoholgehalt = nAlkoholgehalt;
	return true;
}

char * CGetraenk::get_Name()
{
	return Name;
}

void CGetraenk::display()
{
	CProdukt::display();
	std::cout << Name << ' ' << Kategorie << ' ' << Alkoholgehalt/100 << '\n';
}

