#ifndef CPOCO_H_
#define CPOCO_H_

class CPoco {
	
	protected:
		
		double x, y, c, Pi;
	
	public:
		
		CPoco(){};
		
		CPoco(double _x, double _y, double _c, double _Pi): x(_x), y(_y), c(_c), Pi(_Pi){};
		
		//metodos set
		void setX(double _x);
		void setY(double _y);
		void setC(double _c);
		void setPi(double _pi);
		
		//metodos get
		
		double getX();
		double getY();
		double getC();
		double getPi();
		
		~CPoco(){};
	
};

#endif
