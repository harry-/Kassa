#pragma once
#include "CProdukt.h"
class CGetraenk : public CProdukt
{
protected:
	char* Name{ nullptr };
	char Kategorie{ 0 };
	short unsigned Alkoholgehalt{ 0 };

public:
	void display();
	CGetraenk();
	~CGetraenk();
	CGetraenk(const char * nBeschreibung, const char * nDatum, const unsigned int nPreis, const char* nName, const unsigned short nKategorie, const unsigned short nAlkoholgehalt);
	CGetraenk(CGetraenk & original);
	CGetraenk(CGetraenk && original);
	CGetraenk & operator=(CGetraenk & original);
	CGetraenk & operator=(CGetraenk && original);
	bool setName(const char * nName);
	bool setKategorie(const char nKategorie);
	bool setAlkoholgehalt(const unsigned short nAlkoholgehalt);
	char * get_Name();
};

