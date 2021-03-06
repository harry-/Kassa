#include "CProdukt.h"
#include "CFleisch.h"
#include "CGetraenk.h"
#include "GemueseObst.h"
#include "CScanner.h"
#include "CKassa.h"

#include <iostream>
#include <fstream>
#include <limits>

#include <Windows.h>
#include "ClearScreen.h"


void clearCin();

namespace {
    /*------casted umlaute in der konsole direkt um :))------*/
    const unsigned char AE = static_cast<unsigned char>(142);//
    const unsigned char ae = static_cast<unsigned char>(132);//
    const unsigned char OE = static_cast<unsigned char>(153);//
    const unsigned char oe = static_cast<unsigned char>(148);//
    const unsigned char UE = static_cast<unsigned char>(154);//
    const unsigned char ue = static_cast<unsigned char>(129);//
    const unsigned char ss = static_cast<unsigned char>(225);//
    /*-------------------------------------------------------*/

    const int kMaxObjects = 3;
    const char* kOffset= "\n\t\t\t";
	const char* kOffsetOnly = "\t\t\t";
	const std::int32_t cIntMax = 999999;

    // const std::int32_t cIntMax = std::numeric_limits<std::int32_t>::max();
	const int kMaxLength = 50;
}


int main()
{
	
   std::ofstream out("test.txt");

   // Get the rdbuf of clog.
   // We need it to reset the value before exiting.
   auto old_rdbuf = std::clog.rdbuf();

   // Set the rdbuf of clog.
   std::clog.rdbuf(out.rdbuf());
	
	std::clog << USHRT_MAX << '\n' << UINT_MAX << '\n';

	CFleisch* fleisch = new CFleisch{};
	delete fleisch;
	
	CProdukt * products[10] = {NULL};
	CProdukt * itemsChosen[10] = {NULL};

	CProdukt *produkt = new CFleisch{};
	delete produkt;

	//CProdukt * Einkauf[10] = {};

	//CProdukt ** products2 = new CProdukt*[5];

	products[0] = new CFleisch("beschreibungstext", "2.3.2003", 4344, "Schopf", 1);
	products[1] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Gemischter Satz", 1, 1400);
	products[2] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Almdudler", 1, 0);
	products[3] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Inlaender Rum", 1, 3800);
	products[4] = new GemueseObst("beschreibungstext", "2.3.2003", 100, "eine Banane", 2);
	
	int input{-1};
	unsigned short counterChosenItems{ 0 };

	while (counterChosenItems<10)
	{
		clear();
		if (counterChosenItems)
		{
			std::cout << "Bisherige Auswahl:\n";
			for (auto i = 0; i < counterChosenItems; i++)
				std::cout << itemsChosen[i]->get_Name() << '\n';
		}
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
		{
			if (products[i])
			{
				std::cout << std::setw(50) << i+1 << ".)" << products[i]->get_Name();
				std::cout << " (" << (float) (products[i]->get_Preis() / float(100)) << ")\n";
			}
		}
		std::cout << "\nDruecken Sie 0 um die Auswahl zu beenden\n";
		std::cout << "Auswahl: ";
		std::cin >> input;

		if (!input)
			break;

		if (products[input-1])
		{
			itemsChosen[counterChosenItems] = products[input-1];
			counterChosenItems++;
		}
	
	}

	CKassa kassa;
	//CFleisch fleisch2;
	CScanner scanner(&kassa);

	//for(int i = 0; i < 10; i++)
	//	if(products[i])
	//		products[i]->Display();
	for (int i = 0; i < 10; i++)
	{
		if (itemsChosen[i])
		{
			scanner.ScanProduct(itemsChosen[i]);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (products[i])
		{
			delete products[i];
		}
	}
	
	kassa.Display();
	//kassa.~CKassa();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memoryleaks
	clearCin();
	std::cin.get();
	return 0;
}


void clearCin()
{
	std::cin.clear();
	std::cin.ignore(cIntMax, '\n');
}

