#include "CProdukt.h"
//
class CGetraenk :  public CProdukt
{
    private:
        std::string Name;
        float Alkoholgehalt;

    public:
        void Display ();

};
