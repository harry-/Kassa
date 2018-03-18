#pragma once
#include "CProdukt.h"
class GemueseObst :
	public CProdukt
{
protected:
	char * Name{ nullptr };
	unsigned short int Kategorie{ 0 };
public:
	GemueseObst();
	~GemueseObst();
	GemueseObst(const char * nBeschreibung, const char * nDatum, unsigned int nPreis, const char * nName, unsigned short int nKategorie);
	GemueseObst(const GemueseObst & original);
	GemueseObst & operator=(const GemueseObst & original);
	bool set_Name(const char * nName);
	char * get_Name();
	bool set_Kategorie(unsigned short int nKategorie);
	unsigned short int get_Kategorie();
	void display();
	GemueseObst & operator=(const GemueseObst && original) = delete; // no overloaded move operator
	GemueseObst(const GemueseObst && original) = delete; // no move constructor
};


