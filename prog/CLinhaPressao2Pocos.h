
#ifndef CLINHAPRESSAO2POCOS_H
#define CLINHAPRESSAO2POCOS_H
#include <iostream > 
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

#include "CGnuplot.h"
#include "CLinhasEquipotenciais.h"

//DECLARO AQUI
class CLinhaPressao2Pocos : public CLinhasEquipotenciais {
	
public:
	
	///metodos especificos 	
	double AreaInvadidaBT(double C); // declaro aqui mesmo tendo no ClinhasEquipotenciais???
	double Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi);
	double R(double C,double r1,double r2, double r3 = 0.0 );
	vector <double> CalculoDoVetorRaio(double C,double r1,double r2, double r3);
	double X0(double C, double R);
	double CLinhasEquipotenciais::CalculoDoVetorX(double raio; double deslocamento = 0.0 ); // declaro a outra classe aqui ???? ou so no cpp ?
	double CLinhasEquipotenciais::CalculoDoVetorY(double raio; double deslocamento = 0.0);
	void PrintLinhaPressao2P();
};
#endif // CLINHAPRESSAO2POCOS_H
