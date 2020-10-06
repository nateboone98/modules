#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "list.h"


int main(void) {

  car_t *car1, *car2, *car3, *car4;
  int32_t icar1, icar2, icar3, icar4;
  
   //creating all the cars
  car1 = malloc(sizeof(car_t));
  car2 = malloc(sizeof(car_t));
  car3 = malloc(sizeof(car_t));
  car4 = malloc(sizeof(car_t));

  car1->next = NULL;
  strcpy(car1->plate, "plate1");
  car1->price = 10000;
  car1->year = 2015;
  strcpy(car2->plate, "plate2");
  car2->next = NULL;
  car2->price = 19999.99;
  car2->year = 2020;
  car3->next = NULL;
  strcpy(car3->plate, "plate3");
  car3->price = 800;
  car3->year = 1999;
  car4->next = NULL;
  strcpy(car4->plate, "plate4");
  car4->price = 8000;
  car4->year = 2018;
  
  //place all the cars into the list
  icar1 = lput(car1);
  printf("car1 success: %d\n", icar1);
  icar2 = lput(car2);
  printf("car2 success: %d\n", icar2);
  icar3 = lput(car3);
  printf("car3 success: %d\n", icar3);
  icar4 = lput(car4);
  printf("car4 success: %d\n", icar4);
  
  free(car1);
  free(car2);
  free(car3);
  free(car4);

  exit(EXIT_SUCCESS);
  }