#ifndef CPOSICAOAGUAINJETADASTILES_H_
#define CPOSICAOAGUAINJETADASTILES_H_

#include <vector>

#include "CPosicaoAguaInjetada.h"

class CPosicaoAguaInjetadaStiles : CPosicaoAguaInjetada{
	
	public:
		
		CPosicaoAguaInjetadaStiles(){};
		
		std::vector <double> VazaoInjecao(double _krw,double _mw, double _largura,double _dp, std::vector <double> _k, double _bw, double _comprimento, std::vector <double> _espessurac);
		std::vector <double> PosicaoAguaInjetada(std::vector <double> _k,double _largura);
        std::vector <double> EfVert(std::vector<double> _posicaoc, std::vector<double> _espessurac, double _largura, double _espessuraTotal);
        void EfVertTotal();
		double GetEfVertTotal();
		std::vector<double> GetPosicao();
		void VazaoTotal();
		double GetVazaoTotal();
	
		~CPosicaoAguaInjetadaStiles(){}; 
		
};

#endif