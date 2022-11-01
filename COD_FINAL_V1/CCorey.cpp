#include "CCorey.h"
#include <cmath>
#include <iostream>

void CCorey::calcSwn(double _swi, double _sor){
	double a;
	for (double i = _swi; i <=(1.0 - _sor)+.01; i+= .01){
		a = (i - _swi)/(1.0 - _swi - _sor);
		sw.push_back(a);	
	}
	
}

void CCorey::calcKro(std::vector<double> _sw){
	
	for(double sw:_sw)
		kro.push_back(K0ro*pow(1 - sw, No));
	
}

void CCorey::calcKrw(std::vector<double> _sw){
	
	for(double sw:_sw)
		krw.push_back(K0rw*pow(sw, Nw));
	
}

void CCorey::setK0rw(double _K0rw){
	
	K0rw = _K0rw;
	
}

void CCorey::setK0ro(double _K0ro){
	
	K0ro = _K0ro;
	
}

void CCorey::setNo(double _No){
	
	No = _No;
	
}

void CCorey::setNw(double _Nw){
	
	Nw = _Nw;
	
}

std::vector<double> CCorey::getSw(){
	
	return sw;
	
}

std::vector<double> CCorey::getKro(){
	
	return kro;
	
}

std::vector<double> CCorey::getKrw(){
	
	return krw;
	
}
