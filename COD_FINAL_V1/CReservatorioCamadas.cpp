#include "CReservatorioCamadas.h"

using namespace std;

void CReservatorioCamadas::SetBo(double _bo)
{
	
	bo = _bo;	
	
}

void CReservatorioCamadas::SetBw(double _bw)
{
	
	bw = _bw;
	
}

void CReservatorioCamadas::SetDp(double _dp)
{
	
	dp = _dp;
	
}

void CReservatorioCamadas::SetMo(double _mo)
{
	
	mo = _mo;
	
}

void CReservatorioCamadas::SetMw(double _mw)
{
	
	mw = _mw;
	
}

void CReservatorioCamadas::SetSg(double _sg)
{
	
	sg = _sg;
	
}

void CReservatorioCamadas::SetLargura(double _largura)
{

	largura = _largura;

}

void CReservatorioCamadas::SetComprimento(double _comprimento)
{

	comprimento = _comprimento;

}

void CReservatorioCamadas::SetEspec(std::vector<double> _espessurac)
{
	
	espessurac = _espessurac;
	
}

void CReservatorioCamadas::SetK(std::vector<double> _k)
{
	
	k = _k;
	
}

void CReservatorioCamadas::CalcEspessT()
{
    espessuraTotal = 0;
    for(double espessura:espessurac) 
    {
        espessuraTotal += espessura;
    }
}

void CReservatorioCamadas::CalcM(){

	M = (CReservatorio::GetKrw()/mw)/(CReservatorio::GetKro()/mo);

}

double CReservatorioCamadas::GetBo()
{
	
	return bo;	
	
}

double CReservatorioCamadas::GetBw()
{
	
	return bw;
	
}

double CReservatorioCamadas::GetDp()
{
	
	return dp;
	
}

double CReservatorioCamadas::GetMo()
{
	
	return mo;
	
}

double CReservatorioCamadas::GetMw()
{
	
	return mw;
	
}

double CReservatorioCamadas::GetSg()
{
	
	return sg;
	
}

double CReservatorioCamadas::GetM()
{

    return M;

}

double CReservatorioCamadas::GetLargura()
{

	return largura;

}

double CReservatorioCamadas::GetComprimento()
{

	return comprimento;

}

vector <double> CReservatorioCamadas::GetEspec()
{
			
	return espessurac;
	
}

vector <double> CReservatorioCamadas::GetK()
{
	
	return k;
	
}

double CReservatorioCamadas::GetEspessuraTotal()
{

    return espessuraTotal;
    
}
