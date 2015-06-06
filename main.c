#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculatestring.h"

int main(int argc, char *argv[]){
	char expression[100] = "";
	int i = 0;
	double total_d;
	long total_l;
	if(argc <= 1){
		printf("You must give an expression in parameters.\n");
		exit(EXIT_FAILURE);
	}
	for(i = 1 ; i < argc ; i++){
		strcat(expression, argv[i]);
	}
	if(calculatestring(expression, &total_l, &total_d) == EXIT_SUCCESS){
		if(strchr(expression, '.') == NULL)
			printf("%ld\n", total_l);
		else
			printf("%lf\n", total_d);
	}
	else{
		printf("An error has occurred. Please check your expression.\n");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;	
}
