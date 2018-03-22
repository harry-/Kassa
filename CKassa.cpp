#include "CKassa.h"

CKassa::~CKassa()
{
	for (auto i = 0; i < productCount; i++)
	{
		if (products[i])
		{
			delete products[i];
			products[i] = nullptr;
		}
	}
}

int CKassa::Berechnen(CProdukt * product)
{
	int price = product->get_Preis();

	switch (product->get_Kategorie())
	{
	case 1:
		price += price*0.05;
		break;
	case 2:
		price += price*0.1;
		break;
	case 3:
		price += price*0.25;

	}
	//std::clog << typeid(*product).name();

	//if (!strcmp(typeid(*product).name(), "class CFleisch"))
	//{
	//	std::clog << "Fleisch!\n";
	//	products[productCount] = new CFleisch();

	//}
	//else if (!strcmp(typeid(*product).name(), "class CGetraenk"))
	//{
	//	std::clog << "Trinken!\n";
	//	products[productCount] = new CGetraenk();

	//}
	//else if (!strcmp(typeid(*product).name(), "class GemueseObst"))
	//{
	//	std::clog << "Obst!\n";
	//	products[productCount] = new GemueseObst();
	//}
	
	//*products[productCount] = *product;
	//products[productCount]->set_Name(product->get_Name());


	products[productCount] = product->clone();
	products[productCount]->set_Preis(price);
	productCount++;

	Rechnung += price;
	return price;
}

void CKassa::Display()
{
	std::unordered_map<std::string, int> pos;
	std::unordered_map<std::string, unsigned short> items;

	for (int i = 0; i < productCount; i++)
	{
		pos[products[i]->get_Name()] += products[i]->get_Preis();
		items[products[i]->get_Name()]++;
	}

	const short  unsigned poswidth{ 50 };
	const short unsigned countwidth{ 20 };
	const short unsigned pricewidth{ 20 };

	clear();
	std::cout << std::fixed << std::setprecision(2) << std::setw(poswidth) << "Position" << std::setw(countwidth) << "Stk." << std::setw(pricewidth) << "Preis" << '\n';
	for (auto it = pos.begin(); it != pos.end(); it++)
	{
		std::cout << std::setw(poswidth) << it->first << std::setw(countwidth) << items[it->first] << std::setfill('.') <<std::setw(pricewidth) << it->second / (float)100 << std::setfill(' ') <<'\n';
	}
	std::cout << std::setw(poswidth) << "Rechnungsbetrag" << std::setw(countwidth)<< ' ' << std::setw(pricewidth) << Rechnung / (float)100 << '\n';
}

