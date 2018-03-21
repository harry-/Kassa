#include "CScanner.h"

CScanner::CScanner(CKassa * kassa)
{
	this->kassa = kassa;
}

bool CScanner::ScanProduct(CProdukt * product)
{
	kassa->Berechnen(product);
	return true;

}
