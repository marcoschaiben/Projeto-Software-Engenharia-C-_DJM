#ifndef CRESERVATORIOCAMADAS_H_
#define CRESERVATORIOCAMADAS_H_

#include <vector>

#include "CReservatorio.h"

class CReservatorioCamadas : CReservatorio
{
	
	protected:

		double bo, bw, dp, mo, mw, sg, M, largura, comprimento, espessuraTotal;
		
		std::vector <double> espessurac, k;
		
		

	public:	
	
		CReservatorioCamadas(){};
		
		CReservatorioCamadas(double _bo, double _bw, double _dp, double _mo, double _mw, double _sg, double _largura, double _comprimento, CReservatorio reservatorio):bo(_bo), bw(_bw), dp(_dp), mo(_mo), mw(_mw), sg(_sg), largura(_largura), comprimento(_comprimento){ M = (reservatorio.GetKrw()/mw)/(reservatorio.GetKro()/mo);};
	
		//entrada de dados
		
		void SetBo(double _bo);
		void SetBw(double _bw);
		void SetDp(double _dp);
		void SetMo(double _mo);
		void SetMw(double _mw);
		void SetSg(double _sg);
		void SetLargura(double _largura);
		void SetComprimento(double _comprimento);
		void SetEspec(std::vector<double> _espessurac);
		void SetK(std::vector<double> _k);
		
        //metodo

        void CalcEspessT();
		void CalcM();

		//Saida de dados
		
		double GetBo();
		double GetBw();
		double GetDp();
		double GetMo();
		double GetMw();
		double GetSg();
        double GetM();
		double GetLargura();
		double GetComprimento();
        double GetEspessuraTotal();
		std::vector <double> GetEspec();
		std::vector <double> GetK();
	
		~CReservatorioCamadas(){};
		
};

#endif