// libraries : 
#include <stdio.h>
#include "player.h"
#include <math.h>
/*-----------------------------------------------------------------------*/
// a fonction which asks you to input a complex number :
nbr_C input(double _Re,double _Im,char _c[3])
{
	printf("give the Real part of %s : ",_c);
	scanf("%Lf",&_Re);
	printf("give the Imaginary part of %s  : ",_c);
	scanf("%Lf",&_Im);
	nbr_C z = {_Re,_Im} ;
	return z ; 
}
/*-----------------------------------------------------------------------*/
// a fonction which shows a complex number in the algebraic form (a+ib) :

void show_alg (nbr_C _z, char _c[3])
{if (_z.Re != 0 &&_z.Im == 0 )
	{
		printf("%s = %Lf \n",_c,_z.Re);
	}
if  (_z.Re == 0 && _z.Im != 0)
	{
		printf("%s =%Lfi \n",_c,_z.Im );
	}
if (_z.Re == 0 && _z.Im == 0)
	{
		printf("%s = 0 \n",_c );
	}
if (_z.Re != 0 &&_z.Im != 0)
{
	printf("%s = %Lf + %Lfi \n",_c,_z.Re,_z.Im );
}
}
/*-----------------------------------------------------------------------*/
// a fonction which returns the sum of 2 complex numbers:
nbr_C addition(nbr_C  _x, nbr_C _y) 

{	
	nbr_C z ;
	z.Re = _x.Re + _y.Re ;
	z.Im = _x.Im + _y.Im ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
// a fonction which returns the substraction of 2 complex numbers :

nbr_C substraction(nbr_C  _x, nbr_C _y) 
{   nbr_C z ;
	z.Re = _x.Re - _y.Re ;
	z.Im = _x.Im - _y.Im ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
 // a fonction which returns the multiplication of 2 complex numbers :
nbr_CE multiplication(nbr_CE  _x, nbr_CE _y) 

{	
	nbr_CE z ;
	z.mod = _x.mod*_y.mod ;
	z.phase = _x.phase + _y.phase ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
 //  a fonction which returns the division of 2 complex numbers :
nbr_CE division(nbr_CE  _x, nbr_CE _y) 

{	
	nbr_CE z ;
	z.mod = _x.mod/_y.mod ;
	z.phase = _x.phase - _y.phase ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
// a fonction which converts from algebraic form to exponential form :
 nbr_CE converting_exp(nbr_C _z)
 {	nbr_CE z ;
 	z.mod = sqrt(_z.Re*_z.Re + _z.Im*_z.Im);
 	z.phase = atan(_z.Im/_z.Re);

 	return z;
 }
 // a fonction which shows a complex number in the exponential form :
 /*-----------------------------------------------------------------------*/
void show_exp (nbr_CE _z, char _c[3])
{	if (_z.phase == 0)
{
	printf("%s = %Lf \n",_c,_z.mod );
	if (_z.mod ==  0)
	{
		printf("%s = 0 \n",_c);
	}
}if (_z.mod !=  0 && _z.phase != 0)
{
	printf("%s = %Lfexp(%Lfi) \n",_c,_z.mod,_z.phase );
}
	
}
 /*-----------------------------------------------------------------------*/
// a fonction which converts from exponential form to algebraic form  :
nbr_C converting_alg(nbr_CE _y)
{ nbr_C x ;
	x.Re = _y.mod*cos(_y.phase) ;
	x.Im = _y.mod*sin(_y.phase) ;
	return x;

}
 /*-----------------------------------------------------------------------*/
// a fontion which allows to choose between addition and substraction :

nbr_C add_sub(nbr_C _x,nbr_C _y, nbr_C (*op)()) // (*op)() correspont à l'operation demandée
    {
    	return(op(_x,_y)) ;
    }
     /*-----------------------------------------------------------------------*/
// a fontion which allows to choose between multiplication and division :
nbr_CE mux_div(nbr_CE _x,nbr_CE _y, nbr_CE (*op)()) // (*op)() correspont à l'operation demandée
    {
    	return(op(_x,_y)) ;
    }