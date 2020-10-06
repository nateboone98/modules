/* integrate.c --- computes an integral
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Mon Sep 21 22:07:29 2020 (-0400)
 * Version: 2.0
 * 
 * Description: This program approximates the are underneath a curve
 * but is modified to accept either the number of strips to use, or a
 * precise value to be use
 * 
 */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>
#include <inttypes.h>

double f(double x);
double solve(uint32_t n, double a, double b);
void fail(void);

int main (int argc, char *argv[]){
  
	double a, b, result, precision, res1;
  uint32_t steps;
  int checka;
  
  if(argc != 5) {
    fail();
    
    }
  
  checka = strcmp(argv[1], "0");
  //printf("%d is checka\n", checka);
  a=strtod(argv[1], NULL);
  //printf(" a = %f\n", a);
	b=strtod(argv[2], NULL);	
  // printf(" b = %f\n", b);
 
  if(a >= b || b == 0 || (checka != 0 &&  a == 0)){
    fail();
    }

	if(strcmp(argv[3], "-n") ==  0){
    //compute the intgral in using the spcified amout of steps
    steps = strtoul(argv[4], NULL, 10);
    
    if(steps <= 0){ 
    fail();
    }
    
    result = solve(steps, a, b);
	}
	
	else if (strcmp(argv[3],"-p") == 0 ){
		//compute the integral to the designated level of precision
    precision = strtod(argv[4], NULL);
    
    if( precision < 0 || precision > 1){
      fail();
    }
    
    steps = 1;
    result = 0;
    res1 = solve(steps, a, b);
    steps++;
    result = solve(steps, a, b);
    
    while (res1 - result> precision){
      res1 = result;
      steps += steps;
      result = solve(steps, a, b);
    }    
	}
	
	else{
		fail();
	}

	printf("interval: [%lf-%lf],n:%d, result=%lf\n", a,b,steps,result);
	exit(EXIT_SUCCESS);
}


void fail(void){
	printf("usage: integrate a b (-n <steps> | -p <precision>\n");
  exit(EXIT_FAILURE);
}

double solve(uint32_t n, double a, double b){
  
  double lb, ub, delta, result;
  uint32_t i; //check this 
  
  delta = ( b - a ) / n;
  lb = a;
  result = 0;

   
    for ( i = 0; i < n; i++){
      ub = lb + delta;
      result += ((0.5)*(f(lb)+ f(ub))*(delta));
      lb = ub;
    }
    return result;
}

double f(double x){
	double y;
	y =(2*x*x + 9*x + 4);
	return y;
}

