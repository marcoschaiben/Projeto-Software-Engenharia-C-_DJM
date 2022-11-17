#ifndef CPOSICAOAGUAINJETADADYKSTRA_H_
#define CPOSICAOAGUAINJETADADYKSTRA_H_

#include "CPosicaoAguaInjetada.h"

class CPosicaoAguaInjetadaDykstra : CPosicaoAguaInjetada {
	
	public:
		
		CPosicaoAguaInjetadaDykstra(){};
		
		std::vector <double> VazaoInjecao(double _krw,double _mw, double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac, double _M);
		std::vector <double> VazaoBt(double _krw,double _mw, double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac, double _M, std::vector<double> posicao);
		std::vector <double> PosicaoAguaInjetada(std::vector <double> _k, double _L, double _M);
		std::vector <double> EfVert(std::vector<double> _posicaoc, std::vector<double> _espessurac, double _largura, double _espessuraTotal);
		
		double vazaoMedia(std::vector<double> _vazaoInj, std::vector<double> _vazaoBt);
		
		void EfVertTotal();
		double GetEfVertTotal();
		std::vector<double> GetPosicao();
		void VazaoTotal();
		double GetVazaoTotal();
		
		~CPosicaoAguaInjetadaDykstra(){};
	
};

#endif
