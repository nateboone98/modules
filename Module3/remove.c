/* remove.c --- Hidden module that implements the remove function in list.h 
 * 
 * 
 * Author: Nathanael P. Boone, Nick Washington, Esther Omene
 * Created: Sat Oct  3 10:37:43 2020 (-0400)
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "list.h"

/* remove(): find, remove, and return any car with
 * the designated plate; return NULL if not present
 */
car_t *lremove(char *platep){
  
  static car_t temp,*p,*f, *front;
  
  f = front;
  
  for (p = front; p!= NULL; p = p -> next){
  
    if (strcmp(platep, p->plate ) == 0){
      temp = *p;
      f -> next = p -> next;
      free(p);
      return (&temp);
    }
    f = p;
  }
  return (NULL);
}