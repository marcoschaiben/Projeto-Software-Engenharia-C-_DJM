#include "COleoProduzido.h"

void COleoProduzido::OleoProduzido(double _largura, double _comprimento, double _PHI, double _espessuraTotal, double _Sor, double _Swi, double _effVertTotal, double _Bo)
{

    Np = (_largura*_comprimento*_PHI*_espessuraTotal*_effVertTotal*(1.0 - _Sor - _Swi))/_Bo;

}

void COleoProduzido::TempoBreakThrough(double _VazaoTotal)
{
    Tbreak = Np/_VazaoTotal;
}

double COleoProduzido::getTbreak()
{
    return Tbreak;
}

double COleoProduzido::getNp()
{
    return Np;
}