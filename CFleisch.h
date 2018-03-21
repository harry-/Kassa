#pragma once
#include "CProdukt.h"
class CFleisch :
	public CProdukt
{
protected:
	char * Name{ nullptr };
	unsigned short int Kategorie{ 0 };
public:
	CFleisch();
	~CFleisch();
	CFleisch(const char * nBeschreibung, const char * nDatum, unsigned int nPreis, const char * nName, unsigned short int nKategorie );
	CFleisch(const CFleisch & original);

	CFleisch & operator=(const CFleisch & original);

	bool set_Name(const char * nName);
	char * get_Name();
	bool set_Kategorie(unsigned short int nKategorie);
	unsigned short int get_Kategorie();
	void display();
	CFleisch & operator=(const CFleisch && original) = delete; // no overloaded move operator
	CFleisch(const CFleisch && original) = delete; // no move constructor
};


