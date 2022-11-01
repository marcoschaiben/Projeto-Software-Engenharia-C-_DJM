#include "CLinhaPressao3pocos1P2I.h"

double CLinhaPressao3Pocos1P2I::AreaInvadidaBT(double C){
	return 2*pi*C*C;
}

double CLinhaPressao3Pocos1P2I::Pressao(double q,double u, double k,double h,double Pi){
	return -(q*u/4*(log(r1*r1*r2*r2/(r3*r3*r3*r3)))/(2*pi*k*h)) + Pi;
}

double CLinhaPressao3Pocos1P2I::R(double C){
	double r= pow(r1*r2,2)/pow(r3,4);
    r = 2*C*C /(r-1);
    return r;
}

vector<double> CLinhaPressao3Pocos1P2I::CalculoDoVetorRaio( double C){
	 double r = R( C );
	 vector<double> raio;
   	 for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        raio.push_back(sqrt((-cos(2*theta)*r+sqrt((r*r*cos(2*theta))*(r*r*cos(2*theta)) + 2*C*C*r))/2 ));
        }
  return raio;
}

vector<double> CLinhaPressao3Pocos1P2I::CalculoDoVetorX(double R, double C) {
	double x0 = 0.0;
	int i;
	vector<double> xplot;
	vector<double> raio = CalculoDoVetorRaio(C);

	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		xplot.push_back(x0 + raio[i] * cos(theta));
	}
	return xplot;
}

vector<double> CLinhaPressao3Pocos1P2I::CalculoDoVetorY(double R, double C) {
	double y0 = 0.0;
	int i;
	vector<double> yplot;
	vector<double> raio = CalculoDoVetorRaio(C);

	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		yplot.push_back(y0 + raio[i] * sin(theta));
	}
	return yplot;
}
