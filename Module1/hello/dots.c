/* dots.c --- prints some dots 
 * 
 * 
 * Author: Nathanael P. Boone
 * Created: Thur Sep 24 14:05:18 2020 (-0400)
 * Version: 1.0
 * 
 * Description: This program prints n dots t seconds apart
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	int i, n,t;
	
	if(argc!= 3){
		printf("usage: dots n t\n");
		exit(EXIT_FAILURE);
	}
	
	n=atoi(argv[1]);
	t=atoi(argv[2]);

	for(i=0; i<n; i++){
		printf(".");
		fflush(stdout);
		sleep(t);
	}
	
	printf("\n");
	exit(EXIT_SUCCESS);
}
