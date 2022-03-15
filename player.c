// libraries : 
#include <stdio.h>
#include "player.h"
#include <math.h>
/*-----------------------------------------------------------------------*/
// la fonction qui permet la saisie d'un nombre complexe :
nbr_C input(float _Re,float _Im,char _c[3])
{
	printf("give the Real part of %s : ",_c);
	scanf("%f",&_Re);
	printf("give the Imaginary part of %s  : ",_c);
	scanf("%f",&_Im);
	nbr_C z = {_Re,_Im} ;
	return z ; 
}
/*-----------------------------------------------------------------------*/
// la fonction qui permet l'affichage d'un nombre complexe  (a+bi) :

void show_alg (nbr_C _z, char _c[3])
{if (_z.Re != 0 &&_z.Im == 0 )
	{
		printf("%s = %f \n",_c,_z.Re);
	}
if  (_z.Re == 0 && _z.Im != 0)
	{
		printf("%s =%fi \n",_c,_z.Im );
	}
if (_z.Re == 0 && _z.Im == 0)
	{
		printf("%s = 0 \n",_c );
	}
if (_z.Re != 0 &&_z.Im != 0)
{
	printf("%s = %f + %fi \n",_c,_z.Re,_z.Im );
}
}
/*-----------------------------------------------------------------------*/
// la fonction qui permet de retourner la somme de deux nombre complexes :
nbr_C addition(nbr_C  _x, nbr_C _y) 

{	
	nbr_C z ;
	z.Re = _x.Re + _y.Re ;
	z.Im = _x.Im + _y.Im ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
// la fonction qui permet de retourner la difference de deux nombre complexes :

nbr_C soustraction(nbr_C  _x, nbr_C _y) 
{   nbr_C z ;
	z.Re = _x.Re - _y.Re ;
	z.Im = _x.Im - _y.Im ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
 // la fonction qui permet de retourner multiplication de deux nombres complexes :
nbr_CE multiplication(nbr_CE  _x, nbr_CE _y) 

{	
	nbr_CE z ;
	z.mod = _x.mod*_y.mod ;
	z.phase = _x.phase + _y.phase ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
 // la fonction qui permet de retourner multiplication de deux nombres complexes :
nbr_CE division(nbr_CE  _x, nbr_CE _y) 

{	
	nbr_CE z ;
	z.mod = _x.mod/_y.mod ;
	z.phase = _x.phase - _y.phase ;
	return z ;

 } 
 /*-----------------------------------------------------------------------*/
// la fonction qui permet la convertion de la forme algebrique à celle exponetielle :
 nbr_CE convertion_exp(nbr_C _z)
 {	nbr_CE z ;
 	z.mod = sqrt(_z.Re*_z.Re + _z.Im*_z.Im);
 	z.phase = atan(_z.Im/_z.Re);

 	return z;
 }
 // la fonction qui permet de voir l'ecriture exponentielle :
 /*-----------------------------------------------------------------------*/
void show_exp (nbr_CE _z, char _c[3])
{	if (_z.phase == 0)
{
	printf("%s = %f \n",_c,_z.mod );
	if (_z.mod ==  0)
	{
		printf("%s = 0 \n",_c);
	}
}if (_z.mod !=  0 && _z.phase != 0)
{
	printf("%s = %fexp(%fi) \n",_c,_z.mod,_z.phase );
}
	
}
 /*-----------------------------------------------------------------------*/
// la fonction qui permet la convertion de la forme exponetielle à celle algebrique  :
nbr_C converstion_alg(nbr_CE _y)
{ nbr_C x ;
	x.Re = _y.mod*cos(_y.phase) ;
	x.Im = _y.mod*sin(_y.phase) ;
	return x;

}
 /*-----------------------------------------------------------------------*/
// la fonction qui permet le choix entre l'addition et la soustraction :

nbr_C add_sous(nbr_C _x,nbr_C _y, nbr_C (*op)()) // (*op)() correspont à l'operation demandée
    {
    	return(op(_x,_y)) ;
    }
     /*-----------------------------------------------------------------------*/
// la fonction qui permet le choix entre la multiplication et la division :
nbr_CE mux_div(nbr_CE _x,nbr_CE _y, nbr_CE (*op)()) // (*op)() correspont à l'operation demandée
    {
    	return(op(_x,_y)) ;
    }