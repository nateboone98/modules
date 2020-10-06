/* testA.c --- 
 * 
 * 
 * Author: Nicholas E. Washington
 * Created: Sun Oct  4 23:04:26 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "list.h"

// test function: reads out all information about car in list
static void lread(car_t *cp) {
    printf("Car plate: %s\n",cp->plate);
    printf("Car price: %lf\n",cp->price);
    printf("Car year: %d\n\n",cp->year);
}

int main(void) {
  //set up cars to fill the list
  car_t *car1, *car2, *car3;
  
  car1 = (car_t*)malloc(sizeof(car_t));
  car2 = (car_t*)malloc(sizeof(car_t));
  car3 = (car_t*)malloc(sizeof(car_t));
  
  car1->next = NULL;
  strcpy(car1->plate, "test123");
  car1->price = 10000;
  car1->year = 2015;

  car2->next = NULL;
  strcpy(car2->plate, "plate123");
  car2->price = 19999.99;
  car2->year = 2020;

  car3->next = NULL;
  strcpy(car3->plate, "tplate123");
  car3->price = 800;
  car3->year = 1999;
  
  // read from an empty list
  lapply(lread);

  // fill the list
  lput(car1);
  lput(car2);
  lput(car3);
  
  // read from a full list
  lapply(lread);

  free(car1);
  free(car2);
  free(car3);
  
  exit(EXIT_SUCCESS);
}