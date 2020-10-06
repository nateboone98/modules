/* test3.c --- tests an intergace
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Mon Sep 28 16:19:20 2020 (-0400)
 * Version: 1.0
 * 
 * Description: This program tests the reusable module integrate.c
 * through the interface integrate.h
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "integrate.h"
#include <stdint.h>
#include <inttypes.h>

double f(double x){
	double y;
	y =(2*x+ 3);
	return y;
  }

int main(void){

	double a,b,p,rp;
	uint32_t sp;
	int32_t result;

	a=12;
	b=0;
	p=0.0001;
  rp = 0;
	sp = 1;
	
	result = integrate(f,a,b,p, &rp, &sp);

	if(result == 0){
    printf("interval: [%lf-%lf],n:%d, result=%lf\n", a,b,sp,rp);
    exit(EXIT_SUCCESS);
	}
	else{
    printf("test3.c has failed\n");
    exit(EXIT_FAILURE);
  }
}
