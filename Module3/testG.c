#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "list.h"


int main(void){

  car_t *car1, *car2, *car3, *car4;
  car_t *get0, *get1, *get2;  
  int res1, res2, res0;
   //creating all the cars
  car1 = (car_t*)malloc(sizeof(car_t));
  car2 = (car_t*)malloc(sizeof(car_t));
  car3 = (car_t*)malloc(sizeof(car_t));
  car4 = (car_t*)malloc(sizeof(car_t));


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
  
  //get from an empty list
  get0 = lget();
  if(get0 == NULL) {
    res0 = 0;
    }  
  printf("get0 success: %d.\n", res0);
  
  //place all the cars into the list
  lput(car1);
  lput(car2);
  lput(car3);
  lput(car4);
  
  //get from a nonempty list
  get1 = lget();
  res1 = strcmp(get1->plate, "plate4");
  printf("get1 success: %d. plate: %s\n", res1, get1->plate);
  
  get2 = lget();
  res2 = strcmp(get2->plate, "plate3");
  printf("get2 success: %d. plate: %s\n", res2, get2->plate);
  
  free(car1);
  free(car2);
  free(car3);
  free(car4);

  
  exit(EXIT_SUCCESS);
  
  }