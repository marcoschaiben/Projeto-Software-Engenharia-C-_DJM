#ifndef CSOLVERINFLUXO_H
#define CSOLVERINFLUXO_H

#include <vector>
#include <cmath>

#include "CReservatorioCamadas.h"
#include "CReservatorio.h"
#include "CGnuplot.h"
#include "CPosicaoAguaInjetadaStiles.h"
#include "CPosicaoAguaInjetadaDykstra.h"
#include "COleoProduzido.h"
#include "CLinhasEquipotenciais.h"
#include "CPoco.h"
#include "CLinhaPressao2Pocos.h"
#include "CLinhaPressao3Pocos1P2I.h"
#include "CLinhaPressao3Pocos2P1I.h"
#include "CCorey.h"
#include "CFluxoFracionario.h"

class CSolverInfluxo {

protected:

    CReservatorioCamadas camadas;
    CReservatorio reservatorio;
    CPoco poco;
    CPosicaoAguaInjetadaStiles stiles;
    CPosicaoAguaInjetadaDykstra dykstra;
    COleoProduzido oleo;
    CLinhasEquipotenciais* linhas;
    CGnuplot plot, plot1, plot2, plot3, plot4, plot5;
    std::vector<double> xplot, yplot;
    CCorey corey;
    CFluxoFracionario fluxofracionario;

private:

    void EntradaDadosReservatorio();
    void EntradaDadosCamadas();
    void EntradaDadosRochaReservatorio();
    void EntradaDadosPoco();
    void Plot(); 
    double kbarra(std::vector<double> k, std::vector<double> h);
    double r1(double _c, double x, double y);
	double r2(double _c, double x, double y);
	double r3(double x, double y);
	void printResults(double _x, double _y, double _c, double _q, double _mi, double _kbarra, double _h, double _pi);
    

public:

    CSolverInfluxo(){};

    void Simular();         

    ~CSolverInfluxo(){};    
};

#endif 
