#pragma once
#include "CProdukt.h"
#include "CFleisch.h"
#include "CGetraenk.h"
#include "GemueseObst.h"
#include <typeinfo>
#include <unordered_map>
#include <string>
#include <iomanip>
#include "ClearScreen.h"
class CKassa
{
private:
	int Rechnung{ 0 };
	CProdukt * products[10] = {};
	short unsigned productCount{ 0 };

public:
	CKassa(){}
	~CKassa();
	int Berechnen (CProdukt *);
    void Display ();

};
