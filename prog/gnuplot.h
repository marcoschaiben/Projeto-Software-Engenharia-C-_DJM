
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


#ifndef GNUPLOT_H
#define GNUPLOT_H


/**
  * class gnuplot
  * 
  */

class gnuplot
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  gnuplot();

  /**
   * Empty Destructor
   */
  virtual ~gnuplot();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //

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

};

#endif // GNUPLOT_H
