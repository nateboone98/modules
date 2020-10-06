#include<stdio.h>

void displayBoard(int x, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib); /*displays the game board*/
int gameWon(int x, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib);   /*Checks to see if the game is over*/
void readGame(int x);  /*Opens a file from an old game*/
void writeGame(int x, int *j, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib);       /*saves the game*/ 
void startGame(int x, int *j, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib);    /*option to start a new game or an already existing one*/
void Move(int x,int *j, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib); /*lets the player make a move*/

 
int main(void){
  int j=0;  
  int i;
  int x=0;
  int y=0; /*don't forget to change this*/
  char ab,bb,cb,db,eb,bc,gb,hb,ib;      /* place holders for the spaces, X's and O's*/
    ab=32;
    bb=32;
    cb=32;
    db=32;
    eb=32;
    bc=32;
    hb=32;
    ib=32;
    
   startGame(x, &j, &ab, &bb, &cb,&db, &eb, &bc, &gb, &hb, &ib );
   //while (y==0){
     for(i=1; i<3; i++){
   Move(x, &j, &ab, &bb, &cb,&db, &eb, &bc, &gb, &hb, &ib);
   displayBoard(1, &ab, &bb, &cb, &db, &eb, &bc, &gb, &hb, &ib);
     }
   //y=gameWon()
   //}
   return(0);
 } 
 
void startGame(int x, int *j, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib){
  int done=1;
  printf("Hello and Welcome to tic-tac toe!\n"); 
  printf("To place your piece on the board enter 1 for the top left corner, 2 for the spot to the right,");
  printf("and so on (9 is the bottom right corner)\n");
  printf("Please enter 0 to start a new game or 12 to open a saved game.");
  scanf("%d", &x);
  while(done){          
    if (x==0){          /*If the user enters 0 then a new game will start, I have used ASCII values for spaces*/
      done=0;
      *j=0;
      *ab=32;
      *bb=32;
      *cb=32;
      *db=32;
      *eb=32;
      *bc=32;
      *hb=32;
      *ib=32;
      displayBoard(x, ab, bb, cb, db, eb, bc, gb, hb, ib); 
    }
    else if(x==12){     /* if the user enters 12 then they can open a previously saved game*/
      done=0;
      //readGame(1);
    }
    else {
      printf("That number is not Valid. Please enter 0 to start a new game or 12 to open a saved game.\n");
      scanf("%d", &x);
    }  
  }       
 }

void displayBoard (int x, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib){  /*This function displays the game board*/
    int i;
        if (x==0){                                      /*This is the new board*/         
            printf("\n%2c |%2c |%2c\n",*ab,*bb,*cb);
            for(i=1; i<=2; i++){
                printf("----------");
                printf("\n%2c |%2c |%2c\n",*ab,*bb,*cb);
            }    
        }
    else if (x==1){                                 /*This is the current game board*/
        printf("\n%2c |%2c |%2c\n",*ab,*bb,*cb);
        printf("------------");
        printf("\n%2c |%2c |%2c\n",*db,*eb,*bc);    
        printf("------------");
        printf("\n %2c |%2c |%2c\n",*gb,*hb,*ib);
    }
    
}  

void Move(int x, int *j, char *ab, char *bb, char *cb,char *db, char *eb, char *bc, char *gb, char *hb, char*ib){
  int n;          /*number for scanning*/
  int done=0;
  
 while (done==0){
  printf("\nPlease take your turn by entering a number (1-9). Enter 0 to start a new game or '10' to save your game"); 
  scanf("%d", &n);
  
  if(n<0 || n>10){             /* Error message in case they enter a number that's not between 1 and 9)*/
    printf("\nThat number is not between 1 and 9."); 
  } 
 // else if (n==10){
    //writeGame();
  //  }
  else if (n==0){
  startGame(0,j, ab, bb, cb,db, eb, bc, gb, hb, ib);
  }      
  else if (n>=1 && n<=9){ 
    if(*j%2==0){
      switch(n){
        case 1: 
          if (*ab!='X' && *ab!='O'){
            *ab='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 2:
           if (*bb!='X' && *bb!='O'){
            *bb='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");   
          break;
        case 3: 
          if (*cb!='X' && *cb!='O'){
            *cb='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 4: 
        if (*db!='X' && *db!='O'){
            *db='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n"); 
          break;
        case 5: 
          if (*eb!='X' && *eb!='O'){
            *eb='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 6: 
          if (*bc!='X' && *bc!='O'){
            *bc='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 7: 
          if (*gb!='X' && *gb!='O'){
            *gb='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 8: 
          if (*hb!='X' && *hb!='O'){
            *hb='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break;
        case 9: 
          if (*ib!='X' && *ib!='O'){
            *ib='X';
            done=1;
          }
          else printf("\nThat space is occupied.\n");
          break; 
      } 
    }  
    else if(*j%2==1){
      switch(n){
        case 1: 
          *ab='O';
          break;
        case 2: 
          *bb='O';
          break;
        case 3: 
          *cb='O';
          break;
        case 4: 
          *db='O';
          break;
        case 5: 
          *eb='O';
          break;
        case 6: 
          *bc='O';
          break;
        case 7: 
          *gb='O';
          break;
        case 8: 
          *hb='O';
          break;
        case 9: 
          *ib='O';
          break; 
      }  
    }  
  }
} 
*j++;                /*This will make sure that j alternates. If its even one player goes. If its odd then the other one goes*/
}