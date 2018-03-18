#include "CFleisch.h"

CFleisch::CFleisch()
{
}

CFleisch::~CFleisch()
{
	if (Name)
		delete[] Name;
	Name = nullptr;
}

CFleisch::CFleisch(const char * nBeschreibung, const char * nDatum, unsigned int nPreis, const char * nName, unsigned short int nKategorie) :
	CProdukt(nBeschreibung, nDatum, nPreis)
{
	if (!set_Name(nName))
		std::cerr << "overloaded constructor called with invalid argument\n";
	if(!set_Kategorie(nKategorie))
		std::cerr << "overloaded constructor called with invalid argument\n";
}

CFleisch::CFleisch(const CFleisch & original) :
	CProdukt(original)
{
	set_Name(original.Name);
	set_Kategorie(original.Kategorie);
}

CFleisch & CFleisch::operator=(const CFleisch & original)
{
	if (this == &original)
		return *this;

	CProdukt::operator=(original);

	set_Name(original.Name);
	set_Kategorie(original.Kategorie);

	return *this;
}

bool CFleisch::set_Name(const char * nName)
{
	if (!nName)
	{
		std::cerr << "set_Name called with illegal argument\n";
		return false;
	}

	if (Name)
	{
		delete[] Name;
		Name = nullptr;
	}

	Name = new char[strlen(nName) + 1];

	if (!Name)
		std::cerr << "memory allocation failed\n";
	else if (copy2(nName, Name))
		return true;

	return false;
}

char * CFleisch::get_Name()
{
	return Name;
}

bool CFleisch::set_Kategorie(const unsigned short int  nKategorie)
{
	if (nKategorie>3||!nKategorie)
	{
		std::cerr << "set_Kategorie called with illigal argument\n";
		return false;
	}
	Kategorie = nKategorie;
	return true;
}

unsigned short int  CFleisch::get_Kategorie()
{
	return Kategorie;
}

void CFleisch::display()
{
	CProdukt::display();
	std::cout << Name << ' ' << Kategorie << '\n';
}
