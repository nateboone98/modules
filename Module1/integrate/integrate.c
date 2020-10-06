/* integrate.c --- computes an integral
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Mon Sep 21 22:07:29 2020 (-0400)
 * Version: 1.0
 * 
 * Description: This program approximates the are underneath a curve 
 * 
 */
#include <stdio.h>

double f(double x){
	double y;
	y =(2*x*x + 9*x + 4);
	return y;
}

int main (void){
	double a, b, result, lb, ub, delta;
	int i,n;
	a=3;
	b=12;
	n=100;
	delta = (b-a)/n;
	result = 0;	
	lb = a;
	for ( i = 0; i < n; i++){
		ub = lb + delta;
		result += ((0.5)*(f(lb)+ f(ub))*(delta));
		lb = ub;
	}
	printf("interval: [%lf-%lf],n:%d, result=%lf\n", a,b,n,result);
	return 0;
}
