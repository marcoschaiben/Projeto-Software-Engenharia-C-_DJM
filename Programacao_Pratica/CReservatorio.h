#ifndef CReservatorio_H_
#define CReservatorio_H_

class CReservatorio {
	
	protected:
		
		double kro, krw, sor, phi, swi, M;
		
	public:
		
		CReservatorio(){};

        CReservatorio(double _kro, double _krw, double _sor, double _phi, double _swi, double _M): kro(_kro), krw(_krw), sor(_sor), phi(_phi), swi(_swi), M(_M){};
		
		// metodos que mudam os valores das variaveis protegidas
		
		void SetKro(double _kro);
		void SetKrw(double _krw);
		void SetSor(double _sor);
		void SetPHI(double _phi);
		void SetSwi(double _swi);
		void SetM(double _M);
		
		// metodos para adquirir os valores das variaveis da classe

		double GetKro();
		double GetKrw();
		double GetSor();
		double GetPHI();
		double GetSwi();
		double GetM();
		
		~CReservatorio(){};	
	
};

#endif
