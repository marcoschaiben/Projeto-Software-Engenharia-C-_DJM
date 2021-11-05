#include <iostream>
#include <vector>
#include <math>

using namespace std;
double const pi = 3.14159265359;
int i = 0;

class CLinhaEq_3Pocos_1Prod_2Inj {
public:
float FAinvBT(double C){
float AinvBT= 2*pi*C*C;
return AinvBT;
}

float FPressao(double q,double u,double r1,double r2, double r3, double k,double h,double Pi){
double P= -(q*u/4*(log(r1*r1*r2*r2/(r3*r3*r3*r3)))/(2*pi*k*h)) + Pi;
return P;
}

float FX1Y1( double C,double r1,double r2, double r3 ){
    double R_,R;
float x1[1000];
float y1[1000];
float r_[1000];

    R_= pow(r1*r2,2)/pow(r3,4);
    R= 2*C*C /(R_-1);  

    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        i=theta*100;
        r_[i]=sqrt((-cos(2*theta)*R+sqrt((R*R*cos(2*theta))*(R*R*cos(2*theta)) + 2*C*C*R))/2 );
        x1[i]= r_[i]*cos(theta);
        y1[i]= r_[i]*sin(theta);
        }
}
};


class CLinhaEq_3Pocos_2prod_1inj {
 
public:
float FAinvBT(double C){
float AinvBT= 2*pi*C*C;
return AinvBT;
};

float FPressao(double q,double u,double r1,double r2, double r3, double k,double h,double Pi){

double P= -(q*u*log(pow(r3,4)/(pow(r1,2)*pow(r2,2))))/(8*pi*k*h) + Pi;
return P;
};

float FX1Y1( double C,double r1,double r2, double r3 ){
   double R_,R;
float x1[1000];
float y1[1000];
float r_[1000];
R_= (r3*r3*r3*r3)/(r1*r1*r2*r2);
                         R=(2*R_* pow(C,2))/(R_-1);
                         

   for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
   
  i=theta*100;
 
       
       
 
  r_[i]= sqrt((cos(2*theta)*R + sqrt(pow(R*R*cos(2*theta),2 ) - (4*C*C*R)/2))/2);
    x1[i]= r_[i]*cos(theta);
    y1[i]= r_[i]*sin(theta);
     
     
    //cout<<i << "=" <<x1[i]<<"\n";
     
};
 
};
};





 class CLinhaEquipotencial_2P {
 
public:
float FAinvBT(double C){
float AinvBT= pow((4*pi*C),2)/3;
return AinvBT;
};

float FPressao(double q,double u,double r1,double r2,double k,double h,double Pi){

double P = ((q*u*log(r2/r1))/(2*pi*k*h) )+ Pi;
return P;
};

float FXplotYplot( double C,double r1,double r2 ){
double R =(r2/r1)*(r2/r1);
double r = 2*(C)*sqrt(R)/(R-1);
double x0= C*(R+1)/(R-1);
double y0= 0;
float xplot[1000];
              float yplot[1000];

for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
  i=theta*100;
 
  xplot[i]= x0 + r*cos(theta);
      yplot[i]= y0 + r*sin(theta);
     
      // cout<<i << "=" <<xplot[i]<<"\n";
     
  }
 
};
};

// Exemplo de separação==================================================================
virtual double R_( double C,double r1,double r2, double r3 = 0.0 ); // na classe base (o mesmo para todas)

double CLinhaEq_3Pocos_1Prod_2Inj::R_( double C,double r1,double r2, double r3=0.0 ) {
    double r_= pow(r1*r2,2)/pow(r3,4);
    r_ = 2*C*C /(r_-1);
    return r_;
}
double CLinhaEq_3Pocos_2prod_1inj::R_( double C,double r1,double r2, double r3 =0.0 ) {
    double r_= (r3*r3*r3*r3)/(r1*r1*r2*r2);
    r_=(2*R_* pow(C,2))/(r_-1);
    return r_;
}
double CLinhaEquipotencial_2P::R_( double C,double r1,double r2, double r3  = 0) {
    double r_= ((r2/r1)*(r2/r1);
    return r_;
}

// Exemplo de separação==================================================================
// Calculo do vetor raio
virtual vector<double> CalculoDoVetorRaio( double C,double r1,double r2, double r3 )=0;

vector<double> CLinhaEq_3Pocos_1Prod_2Inj::CalculoDoVetorRaio( double C,double r1,double r2, double r3 ){
    double r_ = R_( C,r1,r2,r3 );
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        raio[theta*100]=sqrt((-cos(2*theta)*r_+sqrt((r_*r_*cos(2*theta))*(r_*r_*cos(2*theta)) + 2*C*C*r_))/2 );
        }
  return raio;
}
vector<double> CLinhaEq_3Pocos_2Prod_1Inj::CalculoDoVetorRaio( double C,double r1,double r2, double r3 ){
    double r_ = R_( C,r1,r2,r3 );
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        raio[theta*100]=sqrt((cos(2*theta)*r_ + sqrt(pow(r_*r_*cos(2*theta),2 ) - (4*C*C*r_)/2))/2);        
        }
  return raio;
}
vector<double> CLinhaEquipotencial_2P::CalculoDoVetorRaio( double C,double r1,double r2, double r3 ){
    double r_ = R_( C,r1,r2,r3 );
    raio[0] = 2*(C)*sqrt(r_)/(r_-1);
  return raio;
}

double CLinhaEquipotencial::CalculoDoVetorX1(double deslocamento = 0.0 ){
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        double i = theta*100;
        vx[i]= raio[i]*cos(theta)+deslocamento;
        }
}

double CLinhaEquipotencial::CalculoDoVetorY1(double deslocamento = 0.0 ){
    for (double theta = 0;theta <= 2*pi; theta=theta + 0.01 ){
        double i=theta*100;
        vy[i]= raio[i]*sin(theta)+deslocamento;
        }
}