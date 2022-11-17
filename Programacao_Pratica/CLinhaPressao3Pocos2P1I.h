#ifndef CLINHAPRESSAO3POCOS2P1I_H
#define CLINHAPRESSAO3POCOS2P1I_H

#include "CLinhasEquipotenciais.h"
#include <math.h>

using namespace std;

class CLinhaPressao3Pocos2P1I : public CLinhasEquipotenciais {
public:
	CLinhaPressao3Pocos2P1I(double _r1, double _r2, double _r3) : r1{ _r1 }, r2{ _r2 }, r3{ _r3 }{}

///metodos especificos 	
	double AreaInvadidaBT(double C);
	double Pressao(double q,double u,double k,double h,double Pi);
	double R(double C);
	vector<double> CalculoDoVetorRaio(double C);
	vector<double> CalculoDoVetorX(double R, double C = 0.0);
	vector<double> CalculoDoVetorY(double R, double C = 0.0);
private:
	double r1, r2, r3;
};
#endif
