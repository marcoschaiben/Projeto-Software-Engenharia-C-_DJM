#include "CLinhaPressao2Pocos.h"

double CLinhaPressao2Pocos::AreaInvadidaBT(double C){
	return pow((4.0*pi*C),2)/3.0;
}

double  CLinhaPressao2Pocos::Pressao(double q,double u,double k,double h,double Pi){
	return ((q*u*log(r2/r1))/(2.0*pi*k*h) )+ Pi;
}

double CLinhaPressao2Pocos::R( double C) {
    return (r2/r1)*(r2/r1);
}

vector<double> CLinhaPressao2Pocos::CalculoDoVetorX(double R, double C){
	double x0 = X0(C,R);
	int i;
	vector<double> xplot;
	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		xplot.push_back(x0 + (2 * (C)*sqrt(R) / (R - 1)) * cos(theta));
	}
	return xplot;
}

vector<double> CLinhaPressao2Pocos::CalculoDoVetorY(double R, double C){
	double y0 = 0;
	int i;
	vector<double> yplot;

	for (double theta = 0; theta <= 2 * pi; theta = theta + 0.01) {
		i = theta * 100;
		yplot.push_back(y0 + (2 * (C)*sqrt(R) / (R - 1)) * sin(theta));
	}
	return yplot;
}

/// métodos privados

double CLinhaPressao2Pocos::X0(double C, double R) {
	return C * (R + 1.) / (R - 1.);
}

double CLinhaPressao2Pocos::CalculoDoVetorRaio(double C) { /// preciso passasr pro R E PRO RAIO ?
	double r = R(C);
	return 2 * (C)*sqrt(r) / (r - 1);
}
