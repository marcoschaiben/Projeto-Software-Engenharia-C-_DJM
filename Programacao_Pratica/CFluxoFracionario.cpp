#include "CFluxoFracionario.h"

void CFluxoFracionario::calcFluxoFracionarioAgua(std::vector<double> _krw, std::vector<double> _kro, double miw, double mio){
	
	double a;
	
	for(int i =0; i<_krw.size();i++){
		a = (_krw[i]/miw)/((_krw[i]/miw)+(_kro[i]/mio));
		Frw.push_back(a);			
	}	
}

void CFluxoFracionario::calcFluxoFracionarioOleo(std::vector<double> _krw, std::vector<double> _kro, double miw, double mio){
	
	double a;
	
	for(int i =0; i<_krw.size();i++){
		a = (_kro[i]/mio)/((_krw[i]/miw)+(_kro[i]/mio));
		Fro.push_back(a);			
	}	
	
}

std::vector<double> CFluxoFracionario::getFluxoFracionarioAgua(){
	
	return Frw;
	
}

std::vector<double> CFluxoFracionario::getFluxoFracionarioOleo(){
	
	return Fro;
	
}
