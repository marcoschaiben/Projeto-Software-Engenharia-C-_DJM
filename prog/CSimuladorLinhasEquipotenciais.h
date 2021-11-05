
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


#ifndef CSIMULADORLINHASEQUIPOTENCIAIS_H
#define CSIMULADORLINHASEQUIPOTENCIAIS_H


/**
  * class CSimuladorLinhasEquipotenciais
  * 
  */

class CSimuladorLinhasEquipotenciais
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CSimuladorLinhasEquipotenciais();

  /**
   * Empty Destructor
   */
  virtual ~CSimuladorLinhasEquipotenciais();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * escolher o tipo de linha equipotencial;
   * pedir propriedades;
   * calcular;
   * mostrar resultados.
   * @return bool
   */
  bool ExecutarSimulacao()
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

  CLinhasEquipotenciais linhasquipotenciais;

  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  /**
   * Set the value of linhasquipotenciais
   * @param value the new value of linhasquipotenciais
   */
  void setLinhasquipotenciais(CLinhasEquipotenciais value)
  {
    linhasquipotenciais = value;
  }

  /**
   * Get the value of linhasquipotenciais
   * @return the value of linhasquipotenciais
   */
  CLinhasEquipotenciais getLinhasquipotenciais()
  {
    return linhasquipotenciais;
  }

  void initAttributes();

};

#endif // CSIMULADORLINHASEQUIPOTENCIAIS_H
