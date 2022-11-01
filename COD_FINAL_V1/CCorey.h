#ifndef CCOREY_H_
#define CCOREY_H_

#include <vector>

class CCorey {
	
	protected:
		
		std::vector<double> sw, kro, krw;
		double K0rw, K0ro, No, Nw; 
	
	public:
		
		CCorey(){};
		
		void calcSwn(double _swi, double _sor);
		void calcKro(std::vector<double> _sw);
		void calcKrw(std::vector<double> _sw);
		void setK0rw(double _K0rw);
		void setK0ro(double _K0ro);
		void setNo(double _No);
		void setNw(double _Nw);
		std::vector<double> getSw();
		std::vector<double> getKro();
		std::vector<double> getKrw();
		
		~CCorey(){};
	
};

#endif
