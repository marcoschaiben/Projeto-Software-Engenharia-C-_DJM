#ifndef CLINHAPRESSAO3POCOS2P1I_H
#define CLINHAPRESSAO3POCOS2P1I_H

#include "gnuplot.h"
#include "CLinhasEquipotenciais.h"
#include <math.h>
#include <string>
#include <fstream>
#include <iostream


class CLinhaPressao2Pocos : public gnuplot, public CLinhasEquipotenciais //PRECISOOO DISSOOO ??????????????
{
public:
	
///metodos especificos 	
	double AreaInvadidaBT(double C); // declaro aqui mesmo tendo no ClinhasEquipotenciais???
	double Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi);
	double R(double C,double r1,double r2, double r3 = 0.0 );
	vector <double> CalculoDoVetorRaio(double C,double r1,double r2, double r3);
	double CLinhasEquipotenciais::CalculoDoVetorX(double raio; double deslocamento = 0.0 ); // declaro a outra classe aqui ???? ou so no cpp ?
	double CLinhasEquipotenciais::CalculoDoVetorY(double raio; double deslocamento = 0.0);
	void PrintLinhaPressao3pocos2P1I();

};
#endif // CLINHAPRESSAO3POCOS2P1I_H
