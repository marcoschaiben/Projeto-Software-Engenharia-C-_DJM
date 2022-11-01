#include "CPosicaoAguaInjetadaDykstra.h"

using namespace std;

#include <cmath>


vector <double> CPosicaoAguaInjetadaDykstra::VazaoInjecao(double _krw,double _mw,double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac, double _M)
{
	
	double A;
	
	for (int i = 0; i < _k.size(); i++)
	{
		A = (_krw*_comprimento*_dp*86400.00*_k[i]*_espessurac[i])/(_bw*_mw*_largura*_M);
		VazaoInj.push_back(A);
	}
	
	return VazaoInj;
	
}

vector <double> CPosicaoAguaInjetadaDykstra::VazaoBt(double _krw,double _mw,double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac, double _M, vector<double> posicao)
{
	
	double A;
	
		for (int i = 0; i < _k.size(); i++)
	{
		A = (_krw*_comprimento*_dp*86400.00*_k[i]*_espessurac[i])/(_bw*_mw*(posicao[i] + _M*(_largura - posicao[i] )));
		vazaoBt.push_back(A);
	}
	
	return vazaoBt;
}

vector <double> CPosicaoAguaInjetadaDykstra::PosicaoAguaInjetada(vector<double> _k, double _L, double _M){
	
	double A;
	
	for ( int i = 0; i < _k.size() ; i++)
	{
		
		A = _L*((_M - sqrt(pow(_M, 2) + (1- pow(_M, 2))*(_k[i]/_k[0])))/(_M-1));
		
		posicaoc.push_back(A);
		
	}
	
	return posicaoc;
	
}

std::vector<double> CPosicaoAguaInjetadaDykstra::EfVert(std::vector<double> _posicaoc, std::vector<double> _espessurac, double _largura, double _espessuraTotal)
{

    double A;
    for(int i = 0; i < _espessurac.size(); i++)
    {

        A = (_posicaoc[i]*_espessurac[i])/(_largura*_espessuraTotal);
        efVert.push_back(A);

    }

    return efVert;

}

double CPosicaoAguaInjetadaDykstra::vazaoMedia(std::vector<double> _vazaoInj, std::vector<double> _vazaoBt)
{
	
	double A = 0;
	for(int i = 0; i < _vazaoInj.size(); i++)
    {

        A += (_vazaoInj[i]+ _vazaoBt[i]);
    }
	
	vazaoMed = A/2.0;
	return vazaoMed;
	
}

void CPosicaoAguaInjetadaDykstra::EfVertTotal()
{
    efVertTotal = 0;
    for(double eff: efVert)
    {
        efVertTotal += eff;
    }
}

void CPosicaoAguaInjetadaDykstra::VazaoTotal()
{
    vazaoTotal = 0;
    for(double vazao: VazaoInj)
    {
        vazaoTotal += vazao;
    }
} 

double CPosicaoAguaInjetadaDykstra::GetVazaoTotal()
{

    return vazaoTotal;

}


double CPosicaoAguaInjetadaDykstra::GetEfVertTotal()
{

    return efVertTotal;

}

std::vector<double> CPosicaoAguaInjetadaDykstra::GetPosicao(){
    return posicaoc;
}
