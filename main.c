#include "player.h"

// variables of complex type (algebraic): a+bi
nbr_C x,y,z1,z2,z3,z4 ;
// variables of complex type (exponential) : abs*exp(phi*i)
nbr_CE X,Y,Z1,Z2,Z3,Z4;
int main()
{   
	x = input(x.Re,x.Im,"x");
	y = input(y.Re,y.Im,"y");
	show_alg(x,"x");
	show_alg(y,"y");
	X = converting_exp(x);
	Y = converting_exp(y);
	show_exp (X, "x");
	show_exp (Y, "y");
	z1 = add_sub(x,y,addition);
	z2 = add_sub(x,y,substraction);
	Z3 = mux_div(X,Y,multiplication);
	Z4 = mux_div(X,Y,division);
	z3 = converting_alg(Z3);
	z4 = converting_alg(Z4);
	show_alg(z1,"z1");// the result of x+y
	show_alg(z2,"z2");// the result of x-y
	show_alg(z3,"z3");// the result of x*y
	show_alg(z4,"z4");// the result of x/y

	return 0;
}