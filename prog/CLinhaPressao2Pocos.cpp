#include "CLinhaPressao2Pocos.h"
// EU INCLUO ClinhasEquipotenciais aqui também?? ja que eu uso coisas dela???????????????????

double CLinhaPressao2Pocos::AreaInvadidaBT(double C){
	return pow((4*pi*C),2)/3;
}

double  CLinhaPressao2Pocos::Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi){
	return ((q*u*log(r2/r1))/(2*pi*k*h) )+ Pi;
}

double double CLinhaEquipotencial2Pocos::R( double C,double r1,double r2,double r3 =0.0) {
    return (r2/r1)*(r2/r1);
}

vector<double> CLinhaEquipotencial2Pocos::CalculoDoVetorRaio( double C,double r1,double r2, double r3=0.0){ /// preciso passasr pro R E PRO RAIO ?
double r = R( C,r1,r2,r3 );
raio[0] = 2*(C)*sqrt(r)/(r-1);
	return raio;
}

double X0(double C, double R){
	return C*(R+1)/(R-1);
}

double CLinhasEquipotenciais::CalculoDoVetorX(double x0= 0.0 ){
x0 = X0(C,R);
vector <double> xplot = CalculodovetorX(x0) // como retorno aqui se é de outra classe ???????????????????
	return xplot;
}

double CLinhasEquipotenciais::CalculoDoVetorY(double x0= 0.0 ){
y0 = X0(C,R);
vector <double> yplot = Calculodovetory(y0) // como retorno aqui se é de outra classe ?????????????????????
	return yplot;
}

void CLinhaEquipotencial2Pocos::PrintLinhaPressao2P(){
	// como printar esses resultados??????????????????????????????????????
	cout<< "______________________Linhas de Pressao constante durante a injeção com 2 pocos_________________________" << endl;
	cout<< "Area invadida pela agua= "<< AreaInvadidaBT(C)
    cout<< "P("<<x<<","<<y<<")="<<L_2P.FPressao (q,u,r1,r2,k,h,Pi)<< endl;
	cout << L_2P.FXplotYplot(C,r1,r2)<<"\n";
	
}