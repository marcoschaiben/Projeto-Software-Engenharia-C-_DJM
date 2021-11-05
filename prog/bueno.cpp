# include <iostream > 
# include <vector>
# include <math.h>

using namespace std;
double const pi = 3.14159265359;
int i = 0;

class 	CLinhaEq_3Pocos_1prod_2inj {
 	
	 	public:
			float FAinvBT(double C){
				float AinvBT= 2*pi*C*C;
				return AinvBT;
			};
			
				float FPressao(double q,double u,double r1,double r2, double r3, double k,double h,double Pi){
			
			
					double P= -(q*u/4*(log(r1*r1*r2*r2/(r3*r3*r3*r3)))/(2*pi*k*h)) + Pi;
					return P;
				};
			
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
     				
   		   		
   							//	cout<<i << "=" <<x1[i]<<"\n";
   		   							
};
			  
			};
		 };




class 	CLinhaEq_3Pocos_2prod_1inj {
 	
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
		 
		 
		 
		 
		 
 class 	CLinhaEquipotencial_2P {
 	
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
   		   		
   		   						//	cout<<i << "=" <<xplot[i]<<"\n";
   		   							
					  			}
			  
			};
		 };







int main() {
	
	CLinhaEquipotencial_2P L_2P;
	CLinhaEq_3Pocos_2prod_1inj L_3P;
	CLinhaEq_3Pocos_1prod_2inj L_3P2;
	double r1,r2,r3,P,R,r,x0,y0,AinvBT;
	double x = 300; // posicao x do reservatorio
	double y = 100; // posição y do reservatorio
	double C = 300; // distancia entre os poços
	double h = 100; // profyndidade
	double k = 0.3; // permeabilidade
	double u = 4.5; // viscosidade
	double q = 1000;// vazão
	double Pi= 500; // pressao inicial
	float xplot[1000];
	float yplot[1000];
	int i = 0;
	
	r1= sqrt((C-x)*(C-x) + y*y);
	r2= sqrt((C+x)*(C+x) + y*y);
	r3= sqrt(x*x+y*y);
	
	//__________________________________________________________________________________________________________
	
	cout<< "LINHAS DE PRESSÃO CONSTANTE PARA 2 POÇOS" << endl;
	cout<< "AREA INVADIDA  PELA AGUA NO INSTANTE DO BREAKTHROUGH = "<< L_2P.FAinvBT (C)<< "\n";
    cout<< "P("<<x<<","<<y<<")="<<L_2P.FPressao (q,u,r1,r2,k,h,Pi)<< endl;
	cout << L_2P.FXplotYplot(C,r1,r2)<<"\n";

 	
 	
 	//________________________________________________________________________________________________________
 	
 	cout << "___________LINHAS EQUIPOTENCIAIS MODELO 3 POÇOS ( 2 PRODUTORES E 1 INJETOR)__________________"<< endl;
 	cout<< "AREA INVADIDA  PELA AGUA NO INSTANTE DO BREAKTHROUGH = "<< L_3P.FAinvBT (C)<< "\n";
 	cout<< "P("<<x<<","<<y<<")="<<L_3P.FPressao (q,u,r1,r2,r3,k,h,Pi)<< endl;
	cout << L_3P.FX1Y1(C,r1,r2,r3)<<"\n";
 	
 	
 	//________________________________________________________________________________________________________
 	
 	cout << "___________LINHAS EQUIPOTENCIAIS MODELO 3 POÇOS ( 1 PRODUTORES E 2 INJETOR)__________________"<< endl;
 	cout<< "AREA INVADIDA  PELA AGUA NO INSTANTE DO BREAKTHROUGH = "<< L_3P2.FAinvBT (C)<< "\n";
 	cout<< "P("<<x<<","<<y<<")="<<L_3P2.FPressao (q,u,r1,r2,r3,k,h,Pi)<< endl;
	cout << L_3P2.FX1Y1(C,r1,r2,r3)<<"\n";

 	

 return 0;
}