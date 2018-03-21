#include "CKassa.h"
#include "CProdukt.h"
//
class CScanner
{
public:
	CScanner() {};
	CScanner(CKassa * kassa);
	bool ScanProduct(CProdukt * product);

private:
	CKassa *kassa;
};
