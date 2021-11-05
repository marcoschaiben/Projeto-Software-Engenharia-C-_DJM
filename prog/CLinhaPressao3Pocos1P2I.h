
#ifndef CLINHAPRESSAO3POCOS1P2I_H
#define CLINHAPRESSAO3POCOS1P2I_H

#include "gnuplot.h"
#include "CLinhasEquipotenciais.h"
#include <math.h>
#include <string>
#include <fstream>
#include <iostream



/**
  * class CLinhaPressao2Pocos
  * 
  */

class CLinhaPressao3pocos1P2I : public gnuplot, public CLinhasEquipotenciais { // PRECISO FAZER ISSO ????????????????????????
public:
///metodos especificos 	
	double AreaInvadidaBT(double C); // declaro aqui mesmo tendo no ClinhasEquipotenciais???
	double Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi);
	double R(double C,double r1,double r2, double r3 = 0.0 );
	vector <double> CalculoDoVetorRaio(double C,double r1,double r2, double r3);
	double CLinhasEquipotenciais::CalculoDoVetorX(double raio; double deslocamento = 0.0 ); // declaro a outra classe aqui ???? ou so no cpp ?
	double CLinhasEquipotenciais::CalculoDoVetorY(double raio; double deslocamento = 0.0);
	void PrintLinhaPressao3Pocos1P2i();

};

#endif // CLINHAPRESSAO3POCOS1P2I_H
