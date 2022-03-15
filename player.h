#ifndef PLAYER_H
#define PLAYER_H
/*-----------------------------------------------------------------------*/
// defining a new type complex (a+bi) : (nbr_C)
typedef struct nbr_C
{
	double Re ;
	double Im ;
}nbr_C;
/*-----------------------------------------------------------------------*/
// defining a new type complex (abs*exp(phi*i)) : (nbr_CE)
typedef struct nbr_CE
{
	double mod ;
	double phase ;
}nbr_CE;
/*-----------------------------------------------------------------------*/
// les proptotypes :
nbr_C input(double _Re,double _Im,char _c[2]);
nbr_CE converting_exp(nbr_C _z);
nbr_C converting_alg(nbr_CE _y);
void show_alg (nbr_C _z, char _c[2]);
void show_exp (nbr_CE _z, char _c[2]);
nbr_C addition(nbr_C  _x, nbr_C _y);
nbr_C substraction(nbr_C  _x, nbr_C _y) ;
nbr_CE multiplication(nbr_CE  _x, nbr_CE _y) ;
nbr_CE division(nbr_CE  _x, nbr_CE _y);
nbr_C add_sub(nbr_C _x,nbr_C _y, nbr_C (*op)());
nbr_CE mux_div(nbr_CE _x,nbr_CE _y, nbr_CE (*op)());

#endif