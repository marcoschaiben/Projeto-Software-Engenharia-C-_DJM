#include "CSimuladorLinhasEquipotenciais.h"

void CSimuladorLinhasEquipotenciais::run() {

	double _r1 = r1(x,y);
	double _r2 = r2(x,y);
	linhas = new CLinhaPressao2Pocos(_r1, _r2, 0.0);
	printResults();

	linhas = new CLinhaPressao3pocos1P2I(_r1, _r2, 0.0);
	printResults();

	linhas = new CLinhaPressao3pocos2P1I(_r1, _r2, 0.0);
	printResults();
}

void CSimuladorLinhasEquipotenciais::printResults() {
	cout << "AREA INVADIDA  PELA AGUA NO INSTANTE DO BREAKTHROUGH = " << linhas->AreaInvadidaBT(C) << "\n";
	cout << "P(" << x << "," << y << ")=" << linhas->Pressao(q, u, k, h, Pi) << endl;
}

double CSimuladorLinhasEquipotenciais::r1(double x, double y) {
	return sqrt((C - x) * (C - x) + y * y);
}

double CSimuladorLinhasEquipotenciais::r2(double x, double y) {
	return sqrt((C + x) * (C + x) + y * y);
}

double CSimuladorLinhasEquipotenciais::r3(double x, double y) {
	return sqrt(x * x + y * y);
}