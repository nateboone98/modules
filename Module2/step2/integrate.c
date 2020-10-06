/* integrate2.c --- computes an integral
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Mon Sep 28 15:08:39 2020 (-0400)
 * Version: 2.1
 * 
 * Description: Produces the integral approximation by reference
 * through a result pointer (rp), and the cumulative number of strip
 * calculations used to produce the approximation through a strip
 * pointer (sp).

 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "integrate.h"

static double solve(double(*f) (double x),uint32_t *n, double a, double b);


int32_t integrate(double(*f) (double x), double a, double b, double p, double *rp, uint32_t *sp){
  
  if( a>b || p < 0 || p>1) {return (1);}
  else{
 
  double res1;
  
    res1 = solve(f,sp, a, b);
    *sp = *sp + 1;
    *rp = solve(f,sp, a, b);
    
    while (res1 - *rp> p){
      res1 = *rp;
      *sp += *sp;
      *rp = solve(f, sp, a, b); 
    }
    
    return(0); 
  }    
}

static double solve(double(*f) (double x),uint32_t *n, double a, double b){
  double lb, ub, delta, result;
  int i;
  
  delta = ( b - a ) / *n;
  lb = a;
  result = 0;
   
    for ( i = 0; i < *n; i++){
      ub = lb + delta;
      result += ((0.5)*(f(lb)+ f(ub))*(delta));
      lb = ub;
    }
    return result;
}
  
