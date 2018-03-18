#include "CProdukt.h"
#include "CFleisch.h"
#include "CGetraenk.h"
#include "GemueseObst.h"

#include <climits>
#include <iostream>

int main()
{
	std::cout << USHRT_MAX << '\n' << UINT_MAX << '\n';

	CFleisch* fleisch = new CFleisch{};
	delete fleisch;
	
	CProdukt * products[10] = {};
	CProdukt * itemsChosen[10] = {};

	CProdukt *produkt = new CFleisch{};
	delete produkt;

	//CProdukt * Einkauf[10] = {};

	//CProdukt ** products2 = new CProdukt*[5];

	products[0] = new CFleisch("beschreibungstext", "2.3.2003", 4344, "Schopf", 1);
	products[1] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Gemischter Satz", 1, 1400);
	products[2] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Almdudler", 1, 0);
	products[3] = new CGetraenk("beschreibungstext", "2.3.2003", 3434, "Inlaender Rum", 1, 3800);
	products[4] = new GemueseObst("beschreibungstext", "2.3.2003", 100, "eine Banane", 2);
	
	char input{};
	unsigned short counterChosenItems{ 0 };

	while (counterChosenItems<10)
	{
		system("cls");
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
				std::cout << i+1 << ".)" << products[i]->get_Name();
				std::cout << " (" << products[i]->get_Preis() << ")\n";
			}
		}
		std::cout << "\nDruecken Sie e um die Auswahl zu beenden\n";
		std::cout << "Auswahl: ";
		std::cin >> input;
		if (input <= '9')
		{
			if (products[input-1])
			{
				itemsChosen[counterChosenItems] = products[input-1];
				counterChosenItems++;
			}
		}
		else if (input == 'e')
			break;
	}

	//for(int i = 0; i < 10; i++)
	//	if(products[i])
	//		products[i]->Display();
	for (int i = 0; i < 10; i++)
	{
		if (products[i])
		{
			products[i]->display();
			delete products[i];
		}
	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memoryleaks
	return 0;
}

