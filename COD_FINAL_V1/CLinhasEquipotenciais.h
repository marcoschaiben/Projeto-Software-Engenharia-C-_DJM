#ifndef CLINHASEQUIPOTENCIAIS_H
#define CLINHASEQUIPOTENCIAIS_H

#include <vector>
using namespace std;
class CLinhasEquipotenciais {
public:
    // declaração de método virtual puro, o igual a zero indica que vai ser implementada nas filhas
    virtual double AreaInvadidaBT(double C) = 0;
    virtual double Pressao(double q, double u, double k, double h, double Pi) = 0;
    virtual double R(double C) = 0;
    virtual vector<double> CalculoDoVetorX(double raio, double deslocamento = 0.0) = 0;
    virtual vector<double>  CalculoDoVetorY(double raio, double deslocamento = 0.0) = 0;
protected:
    const double pi = 3.14159265;
    double r1, r2, r3;
};
#endif
