#ifndef CSIMULADORLINHASEQUIPOTENCIAIS_HPP
#define CSIMULADORLINHASEQUIPOTENCIAIS_HPP

#include <iostream>
#include "CLinhasEquipotenciais.h"
#include "CLinhaPressao2Pocos.h"
#include "CLinhaPressao3Pocos1P2I.h"
#include "CLinhaPressao3Pocos2P1I.h"

class CSimuladorLinhasEquipotenciais {
public:
	void run();
	void printResults();
private:
	CLinhasEquipotenciais* linhas;

	double x = 300; // posicao x do reservatorio
	double y = 100; // posição y do reservatorio
	double C = 300; // distancia entre os poços
	double h = 100; // profyndidade
	double k = 0.3; // permeabilidade
	double u = 4.5; // viscosidade
	double q = 1000;// vazão
	double Pi = 500; // pressao inicial

	double r1(double x, double y);
	double r2(double x, double y);
	double r3(double x, double y);
};
#endif