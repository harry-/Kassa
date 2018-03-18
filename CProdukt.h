#pragma once
#include <iostream>
#include "copy.h"
class CProdukt
{
protected:
	char * Beschreibung{ nullptr };
	char * Datum{ nullptr };
	unsigned int Preis{ 0 }; // in cent
public:
	CProdukt();
	virtual ~CProdukt();
	CProdukt(const char * nBeschreibung, const char * nDatum, const unsigned int nPreis);
	CProdukt(const CProdukt & original);
	CProdukt & operator=(const CProdukt & original);
	bool set_Beschreibung(const char * nBeschreibung);
	bool set_Datum(const char * nDatum);
	bool set_Preis(const unsigned int  nPreis);
	char * get_Beschreibung();
	char * get_Datum();
	unsigned int get_Preis();
	virtual void display() = 0;
	virtual char* get_Name() {};
	CProdukt & operator=(const CProdukt && original) = delete; // no overloaded move operator
	CProdukt(const CProdukt && original) = delete; // no move constructor
};

