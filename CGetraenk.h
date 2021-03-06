﻿#pragma once
#include "CProdukt.h"
class CGetraenk : public CProdukt
{
protected:
	char* Name{ nullptr };
	unsigned short Kategorie{ 0 };
	short unsigned Alkoholgehalt{ 0 };

public:
	void display();
	CGetraenk();
	~CGetraenk();
	virtual CProdukt* clone() const { return new CGetraenk(*this); }
	CGetraenk(const char * nBeschreibung, const char * nDatum, const unsigned int nPreis, const char* nName, const unsigned short nKategorie, const unsigned short nAlkoholgehalt);
	CGetraenk(const CGetraenk & original);
	CGetraenk(CGetraenk && original);
	CGetraenk & operator=(CGetraenk & original);
	CGetraenk & operator=(CGetraenk && original);
	bool set_Name(const char * nName);
	bool setKategorie(const unsigned short nKategorie);
	bool setAlkoholgehalt(const unsigned short nAlkoholgehalt);
	char * get_Name();
};

