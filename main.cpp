#include "CProdukt.h"
#include "CFleisch.h"


int main()
{
	CProdukt * products[10];
	CProdukt ** products2 = new CProdukt*[5];

	products[0] = new CFleisch;
	
	return 0;
}

