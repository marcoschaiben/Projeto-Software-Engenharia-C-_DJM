#ifndef CFLUXOFRACIONARIO_H_
#define CFLUXOFRACIONARIO_H_

#include <vector>

class CFluxoFracionario{
	
	protected:
		
		std::vector<double> Frw, Fro;
	
	public:
		
		CFluxoFracionario(){};
		
		void calcFluxoFracionarioAgua(std::vector<double> _krw, std::vector<double> _kro, double miw, double mio);
		void calcFluxoFracionarioOleo(std::vector<double> _krw, std::vector<double> _kro, double miw, double mio);
		std::vector<double> getFluxoFracionarioAgua();
		std::vector<double> getFluxoFracionarioOleo();
		
		~CFluxoFracionario(){};
	
};


#endif
