#ifndef PLAYER_H
#define PLAYER_H
/*-----------------------------------------------------------------------*/
// definition d'un nouveau type complexe (a+bi) : (nbr_C)
typedef struct nbr_C
{
	float Re ;
	float Im ;
}nbr_C;
/*-----------------------------------------------------------------------*/
// definition d'un nouveau type complexe (abs*exp(phi*i)) : (nbr_CE)
typedef struct nbr_CE
{
	float mod ;
	float phase ;
}nbr_CE;
/*-----------------------------------------------------------------------*/
// les proptotypes :
nbr_C input(float _Re,float _Im,char _c[2]);
nbr_CE convertion_exp(nbr_C _z);
nbr_C converstion_alg(nbr_CE _y);
void show_alg (nbr_C _z, char _c[2]);
void show_exp (nbr_CE _z, char _c[2]);
nbr_C addition(nbr_C  _x, nbr_C _y);
nbr_C soustraction(nbr_C  _x, nbr_C _y) ;
nbr_CE multiplication(nbr_CE  _x, nbr_CE _y) ;
nbr_CE division(nbr_CE  _x, nbr_CE _y);
nbr_C add_sous(nbr_C _x,nbr_C _y, nbr_C (*op)());
nbr_CE mux_div(nbr_CE _x,nbr_CE _y, nbr_CE (*op)());

#endif