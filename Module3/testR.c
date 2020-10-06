/* testR.c --- A test for list.c
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Sun Oct  4 14:23:13 2020 (-0400)
 * Version: 1.0
 * 
 * Description:This program tests the remove functionality in list.c 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "list.h"


int main(void){

  car_t *car1, *car2, *car3, *car4, *car5, *car6, *car7, *car8;
  int32_t icar1, icar2, icar3, icar4;
  
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
  
  car7 = lremove("EmptyListPlate");//remove from an empty list
  
  //place all the cars into the list
  icar1 = lput(car1);
  printf("car1 success: %d\n", icar1);
  icar2 = lput(car2);
  printf("car2 success: %d\n", icar2);
  icar3 = lput(car3);
  printf("car3 success: %d\n", icar3);
  icar4 = lput(car4);
  printf("car4 success: %d\n", icar4);
  
  car8 = lremove("plate4");//remove from a non-empty list at the beggining
  printf("car8 new plate is %s\n", car8->plate);
  
  car5 = lremove("falsePlate");//remove a plate that doesn't exit

  car6 = lremove("plate2");//remove from a non-empty list in the middle
  printf("car6 new plate is %s\n", car6->plate);
    
  car5 = lremove("plate1");//remove from a non-empty list at the end
  printf("car5 new plate is %s\n", car5->plate);
  
  car7 = lremove("plate3");//remove from a non-empty list at both the beggining and the end
  printf("car7 new plate is %s\n", car7 -> plate);

  free(car1);
  free(car2);
  free(car3);
  free(car4);
  
  exit(EXIT_SUCCESS);
}
