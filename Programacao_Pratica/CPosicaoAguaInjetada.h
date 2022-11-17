#ifndef CPOSICAOAGUAINJETADA_H_
#define CPOSICAOAGUAINJETADA_H_

#include <vector>

class CPosicaoAguaInjetada
{
	
	protected:
		
        double efVertTotal, vazaoTotal, vazaoMed;
		std::vector <double> posicaoc, VazaoInj, efVert, vazaoBt;
			
	public:
		
		CPosicaoAguaInjetada(){};
		
		std::vector <double> VazaoInjecao(double _krw,double _mw, double _dp, std::vector <double> _k, double _bw, double _comprimento, double _M, std::vector <double> _posicaoc, std::vector <double> _espessurac);
		std::vector <double> PosicaoAguaInjetada(std::vector <double> _k,double _largura);
		
		~CPosicaoAguaInjetada(){};	
	
}; 

#endif
