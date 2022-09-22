#ifndef CLINHAPRESSAO2POCOS_H
#define CLINHAPRESSAO2POCOS_H

#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

#include "CLinhasEquipotenciais.h"
using namespace std;

class CLinhaPressao2Pocos : public CLinhasEquipotenciais {
public:
	///metodos especificos 	
	CLinhaPressao2Pocos(double _r1, double _r2, double _r3) : r1{ _r1 }, r2{ _r2 }, r3{ _r3 }{}
	double AreaInvadidaBT(double C);
	double Pressao(double q,double u,double k,double h,double Pi);
	double R(double C);
	vector<double> CalculoDoVetorX(double R, double C = 0.0);
	vector<double> CalculoDoVetorY(double R, double C = 0.0);

private:
	double X0(double C, double R);
	double CalculoDoVetorRaio(double C);
	double r1, r2, r3;
};
#endif // CLINHAPRESSAO2POCOS_H
