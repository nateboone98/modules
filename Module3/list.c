/*                                                                              
 * list.c -- implements list.h                                                  
 */
 
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

#define MAXREG 10

static car_t *front = NULL;

/* put(): place a car at the beginning of the list returns 0 if
 * successful; nonzero otherwise
 */
int32_t lput(car_t *cp) {
  if(front == NULL) {
    front = cp;
    printf("car placed at the front of an empty list\n");
    return 0;
  }
  
  cp->next = front;
  front = cp;
  printf("car placed at front of non-empty list\n");
  if(front == cp) {
    return 0;
  }
  else {
    printf("failure");
    return -1;
  }
}

/* get(): remove and return the first car in the list; return NULL if
 * the list is empty
 */
car_t *lget() {

	if(front == NULL) {
	printf("list is empty\n");
    return NULL;
  }
	
  car_t *p1;
  car_t *pn;
  p1 = front;
  pn = front->next;
  front = pn;
  p1->next = NULL;
  return p1;
}



/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {
    car_t *cp;
    if (front==NULL) {
        printf("list empty. can't do that\n\n");
        return;
    }
    cp = front;
    for (cp=front; cp!=NULL; cp=cp->next) {
        fn(cp);
    }
                                                                                                   
}
/* remove(): find, remove, and return any car with the designated
 * plate; return NULL if not present
 */
car_t *lremove(char *platep){
  
  car_t *temp,*p,*f;//temp is the car we remove and return, p is used to keep track of the current car, and f is used to keep track of the previous car
  
  for (p = front; p!= NULL; p = p -> next){
    
    if (strcmp(platep, p->plate ) == 0){//if the plates match
      
      if(p != front){//if we are not at the front then set the previous pointer to skip over the current pointer
        f -> next = p -> next;
      }
      
      if(p == front){// if at the front of the list then set the front to the next car in the list
        front = p ->next;
      }
      
      temp = p;
      temp -> next = NULL;
      return (temp);
    }
		
    f = p;
  }
  
  printf("There are no cars with the license plate %s\n", platep);
  return (NULL);
}

