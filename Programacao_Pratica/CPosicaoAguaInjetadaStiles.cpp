#include "CPosicaoAguaInjetadaStiles.h"

#include <iostream>

using namespace std;

std::vector <double> CPosicaoAguaInjetadaStiles::VazaoInjecao(double _krw,double _mw,double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac)
{
	
	double A;
	
	for (int i = 0; i < _k.size(); i++)
	{
		A = (_krw*_comprimento*_dp*86400.00*_k[i]*_espessurac[i])/(_bw*_mw*_largura);
		VazaoInj.push_back(A);
	}
	
	return VazaoInj;
	
}
std::vector <double> CPosicaoAguaInjetadaStiles::PosicaoAguaInjetada(std::vector <double> _k,double _largura)
{
	
	double A;
	for (int i = 0; i< _k.size(); i++)
    {
	    A = (_largura*_k[i]/(_k[0]));
        posicaoc.push_back(A);
    }
		
	return posicaoc;
	
}

std::vector<double> CPosicaoAguaInjetadaStiles::EfVert(std::vector<double> _posicaoc, std::vector<double> _espessurac, double _largura, double _espessuraTotal)
{

    double A;
    for(int i = 0; i < _espessurac.size(); i++)
    {

        A = (_posicaoc[i]*_espessurac[i])/(_largura*_espessuraTotal);
        efVert.push_back(A);

    }

    return efVert;

}

void CPosicaoAguaInjetadaStiles::EfVertTotal()
{
    efVertTotal = 0;
    for(double eff: efVert)
    {
        efVertTotal += eff;
    }
}

void CPosicaoAguaInjetadaStiles::VazaoTotal()
{
    vazaoTotal = 0;
    for(double vazao: VazaoInj)
    {
        vazaoTotal += vazao;
    }
} 

double CPosicaoAguaInjetadaStiles::GetVazaoTotal()
{

    return vazaoTotal;

}

double CPosicaoAguaInjetadaStiles::GetEfVertTotal()
{

    return efVertTotal;

}

std::vector<double> CPosicaoAguaInjetadaStiles::GetPosicao(){
    return posicaoc;
}