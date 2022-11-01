#ifndef COLEOPRODUZIDO_H_
#define COLEOPRODUZIDO_H_

class COleoProduzido {

    double Np, Tbreak;

public:

    COleoProduzido(){};

    void OleoProduzido(double _largura, double _comprimento, double _PHI, double _espessuraTotal, double _Sor, double _Swi, double _effVertTotal, double _Bo);
    void TempoBreakThrough(double _VazaoTotal);
    double getNp();
    double getTbreak();

    ~COleoProduzido(){};
    
};

#endif 