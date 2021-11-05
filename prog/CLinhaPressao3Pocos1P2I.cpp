#include "CLinhaPressao3pocos1P2I.h"

double CLinhaPressao3pocos1P2I::AreaInvadidaBT(double C){
	return 2*pi*C*C;
}

double CLinhaPressao3pocos1P2I::Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi){
	return -(q*u/4*(log(r1*r1*r2*r2/(r3*r3*r3*r3)))/(2*pi*k*h)) + Pi;
}

double CLinhaPressao3pocos1P2I::R(double C,double r1,double r2, double r3 = 0.0 ){
	double r= pow(r1*r2,2)/pow(r3,4);
    r = 2*C*C /(r-1);
    return r;
}

double CLinhaPressao3pocos1P2I::CalculoDoVetorRaio( double C,double r1,double r2, double r3=0.0){
	 double r = R( C,r1,r2,r3 );
   	 for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        raio[theta*100]=sqrt((-cos(2*theta)*r+sqrt((r*r*cos(2*theta))*(r*r*cos(2*theta)) + 2*C*C*r))/2 );
        }
  return raio;
}

double CLinhasEquipotenciais::CalculoDoVetorX(double x0= 0.0 ){
//x0 = X0(C,R); NAO TENHO X0 AQUI, COMOFAZ ?
vector <double> xplot = CalculodovetorX(x0) // como retorno aqui se é de outra classe ???????????????????
	return xplot;
}

double CLinhasEquipotenciais::CalculoDoVetorY(double x0= 0.0 ){
//y0 = X0(C,R); NAO TENHO Y0 AQUI, COMOFAZ?
vector <double> yplot = Calculodovetory(y0) // como retorno aqui se é de outra classe ?????????????????????
	return yplot;
}
