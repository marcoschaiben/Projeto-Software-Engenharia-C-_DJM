
#ifndef CLINHASEQUIPOTENCIAIS_H
#define CLINHASEQUIPOTENCIAIS_H
#include <iostream > 
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include "CGnuplot.h"


class CLinhasEquipotenciais {
    atributos?
    double posicaoX = 0.0;
    double posicaoY = 0.0;
    double distanciaPoco = 0.0;
    std::vector<double> raio;
    
protected:
 CGnuplot grafico;

public:
    virtual double AreiaInvadidaBT(double C) = 0;
    virtual double Pressao(double q,double u,double k,double h,double Pi,double r1,double r2,double r3 = 0.0);
    virtual double R() = 0; // declaração de método virtual puro, o igual a zero indica que vai ser implementada nas filhas
//     virtual double R() //definição
//     {
//         //conta aqui; pode usar posicaoX posicaoY distanciaPoco raio[i]
//         //double varTempR1 = R1();
//     }
    virtual double R1(/*parâmetro é o que vem de fora*/);
    virtual double R2();
    virtual double R3();
    virtual vector <double> CalculoDoVetorRaio();
    double CalculoDoVetorX(double raio; double deslocamento = 0.0 ); 
    double CalculoDoVetorY(double raio; double deslocamento = 0.0);
    
    double DistanciaPoco() { return distanciaPoco; } // get
    void DistanciaPoco(double dp) { distanciaPoco = dp; } // set
//calculos  e métodos associados
 double C1(){...}; //se o calculo é pequeno, ou usado apenas uma vez, só precisa do método de calculo
 double C2(){...}; //se o calculo é grande e é usado mais de uma vez, eu armazeno o resultado num atributo
 double C3(){...}; 
 double c2; // variável intermediária, criada para economizar tempo de processamento
 void EntradaDados();

};
#endif // CLINHASEQUIPOTENCIAIS_H

Opção 0)
CLinhasEquipotenciais objetoLinhasEquipotenciais; // cria objeto
objetoLinhasEquipotenciais.EntradaDados(); // vai pedir com cout/cin as informações

Opção 1)
CLinhasEquipotenciais objetoLinhasEquipotenciais{px, py,dp,raio}; // cria objetoLinhasEquipotenciais com os atributos

Opção 2)
CLinhasEquipotenciais objetoLinhasEquipotenciais; // cria objetoLinhasEquipotenciais
objetoLinhasEquipotenciais.DistanciaPoco(123.897); // seta propriedade depois

Opção 3)
CLinhasEquipotenciais objetoLinhasEquipotenciais; // cria objetoLinhasEquipotenciais
objetoLinhasEquipotenciais.CalculoDoVetorX(raio, deslocamento); // as propriedades são passada para uma função de calculo



