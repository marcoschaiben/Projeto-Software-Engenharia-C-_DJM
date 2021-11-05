#include "CLinhasEquipotenciais.h"




virtual double CLinhasEquipotenciais::AreiaInvadidaBT(double C){
}


virtual double CLinhasEquipotenciais::Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi){
}

virtual double CLinhasEquipotenciais::R( double C,double r1,double r2, double r3 = 0.0 ){
}

virtual vector <double> CLinhasEquipotenciais::CalculoDoVetorRaio( double C,double r1,double r2, double r3= 0.0){
}

double CLinhasEquipotenciais::CalculoDoVetorX1(double x0 = 0.0 ){
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        double i = theta*100;
        vx[i]= raio[i]*cos(theta)+x0;
        }
        
		return vx;        
}


double CLinhasEquipotenciais::CalculoDoVetorY1(double deslocamento = 0.0 ){
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        double i=theta*100;
        vy[i]= raio[i]*sin(theta)+y0;
        }
        return y0;
}
