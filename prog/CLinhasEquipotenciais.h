
#ifndef CLINHAPRESSAO2POCOS_H
#define CLINHAPRESSAO2POCOS_H
#include "gnuplot.h"
#include "CLinhasEquipotenciais.h"


/**
  * class CLinhaPressao2Pocos
  * 
  */

class CLinhaPressao2Pocos : public gnuplot, public CLinhasEquipotenciais
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CLinhaPressao2Pocos();

  /**
   * Empty Destructor
   */
  virtual ~CLinhaPressao2Pocos();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @param  _R1
   * @param  _R2
   * @param  _R3
   * @param  C
   */
  void Raio(double _R1, double _R2, double _R3 = 0.0, double C)
  {
  }


  /**
   * (double q,double u,double r1,double r2, double r3, double k,double h,double Pi
   * @param  _q
   * @param  _u
   * @param  _R1
   * @param  _R2
   * @param  _R3
   * @param  _k
   * @param  _h
   * @param  _Pi
   */
  void Pressao(double _q, double _u, double _R1, double _R2, double _R3, double _k, double _h, double _Pi)
  {
  }


  /**
   * @param  _C
   * @param  _R
   */
  void X0(double _C, double _R)
  {
  }


  /**
   * @param  _C
   */
  void AreaInvadidaBT(double _C)
  {
  }


  /**
   * @param  _R1
   * @param  _R2
   * @param  _R3
   */
  void R(double _R1, double _R2, double _R3 = 0.0)
  {
  }

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  

  double x0;

  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  /**
   * Set the value of x0
   * @param value the new value of x0
   */
  void setX0(double value)
  {
    x0 = value;
  }

  /**
   * Get the value of x0
   * @return the value of x0
   */
  double getX0()
  {
    return x0;
  }

  void initAttributes();

};

#endif // CLINHAPRESSAO2POCOS_H


#ifndef CLINHASEQUIPOTENCIAIS_H
#define CLINHASEQUIPOTENCIAIS_H

#include "CLinhaPressao3Pocos2P1I.h"
#include "CLinhaPressao2Pocos.h"
#include "CLinhaPressao3Pocos1P2I.h"
#include "CLinhaPressao3Pocos2P1I.h"
#include "CLinhaPressao2Pocos.h"


/**
  * class CLinhasEquipotenciais
  * 
  */

class CLinhasEquipotenciais : public CLinhaPressao3Pocos2P1I, public CLinhaPressao2Pocos, public CLinhaPressao3Pocos1P2I, public CLinhaPressao3Pocos2P1I, public CLinhaPressao2Pocos
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CLinhasEquipotenciais();

  /**
   * Empty Destructor
   */
  virtual ~CLinhasEquipotenciais();

  // Static Public attributes
  //  

  // Public attributes
  //  

  double posicaoX;
  double posicaoY;
  // metade da disntancia entre os poços
  double distanciaPoco;
  vector<double> raio;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of posicaoX
   * @param value the new value of posicaoX
   */
  void setPosicaoX(double value)
  {
    posicaoX = value;
  }

  /**
   * Get the value of posicaoX
   * @return the value of posicaoX
   */
  double getPosicaoX()
  {
    return posicaoX;
  }

  /**
   * Set the value of posicaoY
   * @param value the new value of posicaoY
   */
  void setPosicaoY(double value)
  {
    posicaoY = value;
  }

  /**
   * Get the value of posicaoY
   * @return the value of posicaoY
   */
  double getPosicaoY()
  {
    return posicaoY;
  }

  /**
   * Set the value of distanciaPoco
   * metade da disntancia entre os poços
   * @param value the new value of distanciaPoco
   */
  void setDistanciaPoco(double value)
  {
    distanciaPoco = value;
  }

  /**
   * Get the value of distanciaPoco
   * metade da disntancia entre os poços
   * @return the value of distanciaPoco
   */
  double getDistanciaPoco()
  {
    return distanciaPoco;
  }

  /**
   * Set the value of raio
   * @param value the new value of raio
   */
  void setRaio(vector<double> value)
  {
    raio = value;
  }

  /**
   * Get the value of raio
   * @return the value of raio
   */
  vector<double> getRaio()
  {
    return raio;
  }


  /**
   * @return double
   * @param  _raio
   * @param  _theta
   * @param  x0
   */
  double Vx(double _raio, double _theta, double x0 = 0.0)
  {
  }


  /**
   * @return double
   * @param  _raio
   * @param  _theta
   * @param  y0
   */
  double Vy(double _raio, double _theta, double y0 = 0.0)
  {
  }


  /**
   * @return vector<double>
   * @param  _distanciaPoco
   * @param  _posicaoX
   * @param  _posicaoY
   */
  vector<double> R1(double _distanciaPoco, double _posicaoX, double _posicaoY)
  {
  }


  /**
   * @return vector<double>
   * @param  _distanciaPoco
   * @param  _posicaoX
   * @param  _posicaoY
   */
  vector<double> R2(double _distanciaPoco, double _posicaoX, double _posicaoY)
  {
  }


  /**
   * @return double
   * @param  _distanciaPoco
   * @param  _posicaoX
   * @param  _posicaoY
   */
  double R3(double _distanciaPoco, double _posicaoX, double _posicaoY)
  {
  }


  /**
   * @return double
   * @param  _R1
   * @param  _R2
   * @param  _R3
   * @param  C
   */
  double R_(double _R1, double _R2, double _R3 = 0.0, double C)
  {
  }


  /**
   * @param  _R1
   * @param  _R2
   * @param  _R3
   * @param  C
   */
  void CalculoDoVetorRaio(double _R1, double _R2, double _R3 = 0.0, double C)
  {
  }


  /**
   * @return double
   * @param  C
   */
  double AreaInvadida(double C)
  {
  }


  /**
   * float FPressao(double q,double u,double r1,double r2,double k,double h,double
   * Pi)
   * @param  _q
   * @param  _u
   * @param  _R1
   * @param  _R2
   * @param  _R3
   * @param  _k
   * @param  _Pi
   */
	virtual double Pressão(double _q, double _u, double _R1, double _R2, double _R3 = 0.0, double _k, double _Pi)
  {
  }

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  


  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  void initAttributes();

};

#endif // CLINHASEQUIPOTENCIAIS_H


//________________________________________________________A PARTE_________________________________________________________
#ifndef CLINHASEQUIPOTENCIAIS_H
#define CLINHASEQUIPOTENCIAIS_H

#include "CLinhaPressao3Pocos2P1I.h"
#include "CLinhaPressao2Pocos.h"                   //// NAO ENTENDI POR QUE DISSO???????????????????????????
#include "CLinhaPressao3Pocos1P2I.h"
#include "CLinhaPressao3Pocos2P1I.h"
#include "CLinhaPressao2Pocos.h"
#include <iostream > 
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <iostream>


class CLinhasEquipotenciais{
public:
	
virtual double AreiaInvadidaBT(double C);
virtual double Pressao(double q,double u,double r1,double r2,double r3 =0.0, double k,double h,double Pi); // coloco o virtuall aquiii ??? ou no cpp
virtual double R( double C,double r1,double r2, double r3 = 0.0 );
virtual vector <double> CalculoDoVetorRaio( double C,double r1,double r2, double r3= 0.0);
double CalculoDoVetorX(double raio; double deslocamento = 0.0 ); 
double CalculoDoVetorY(double raio; double deslocamento = 0.0);
		
}
#endif // CLINHASEQUIPOTENCIAIS_H



