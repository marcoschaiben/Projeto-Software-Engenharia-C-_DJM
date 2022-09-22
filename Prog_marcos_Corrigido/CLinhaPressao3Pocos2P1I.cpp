#include "CLinhaPressao3pocos2P1I.h"

double CLinhaPressao3pocos2P1I::AreaInvadidaBT(double C){
	return 2*pi*C*C;
}

double CLinhaPressao3pocos2P1I::Pressao(double q,double u,double k,double h,double Pi){
	return -(q*u*log(pow(r3,4)/(pow(r1,2)*pow(r2,2))))/(8*pi*k*h) + Pi;
}

double CLinhaPressao3pocos2P1I::R(double C){
	double r= (r3*r3*r3*r3)/(r1*r1*r2*r2);
    r=(2*r* pow(C,2))/(r-1);
    return r;
}

vector<double> CLinhaPressao3pocos2P1I::CalculoDoVetorRaio( double C){
   double r = R( C);
   vector<double> raio(100);
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        raio[theta*100]=sqrt((cos(2*theta)*r + sqrt(pow(r*r*cos(2*theta),2 ) - (4*C*C*r)/2))/2);        
        }
  return raio;
}

vector<double> CLinhaPressao3pocos2P1I::CalculoDoVetorX(double R, double C) {
	double x0 = 0;
	int i;
	vector<double> xplot;

	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		xplot[i] = x0 + (2 * (C)*sqrt(R) / (R - 1)) * cos(theta);
	}
	return xplot;
}

vector<double> CLinhaPressao3pocos2P1I::CalculoDoVetorY(double R, double C) {
	double y0 = 0;
	int i;
	vector<double> yplot;

	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		yplot[i] = y0 + (2 * (C)*sqrt(R) / (R - 1)) * sin(theta);
	}
	return yplot;
}