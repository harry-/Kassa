#include "GemueseObst.h"

GemueseObst::GemueseObst()
{
}

GemueseObst::~GemueseObst()
{
	if (Name)
		delete[] Name;
	Name = nullptr;
}

GemueseObst::GemueseObst(const char * nBeschreibung, const char * nDatum, unsigned int nPreis, const char * nName, unsigned short int nKategorie) :
	CProdukt(nBeschreibung, nDatum, nPreis)
{
	if (!set_Name(nName))
		std::cerr << "overloaded constructor called with invalid argument\n";
	if (!set_Kategorie(nKategorie))
		std::cerr << "overloaded constructor called with invalid argument\n";
}

GemueseObst::GemueseObst(const GemueseObst & original) :
	CProdukt(original)
{
	set_Name(original.Name);
	set_Kategorie(original.Kategorie);
}

GemueseObst & GemueseObst::operator=(const GemueseObst & original)
{
	if (this == &original)
		return *this;

	CProdukt::operator=(original);

	set_Name(original.Name);
	set_Kategorie(original.Kategorie);

	return *this;
}

bool GemueseObst::set_Name(const char * nName)
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

char * GemueseObst::get_Name()
{
	return Name;
}

bool GemueseObst::set_Kategorie(const unsigned short int  nKategorie)
{
	if (nKategorie>3 || !nKategorie)
	{
		std::cerr << "set_Kategorie called with illigal argument\n";
		return false;
	}
	Kategorie = nKategorie;
	return true;
}

unsigned short int  GemueseObst::get_Kategorie()
{
	return Kategorie;
}

void GemueseObst::display()
{
	CProdukt::display();
	std::cout << Name << ' ' << Kategorie << '\n';
}
