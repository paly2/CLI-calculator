#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculatestring.h"

int calculatestring(const char *string, long *total_l, double *total_d){
	int i1 = 0, i2 = 0, i3 = 0, end_priority = 0;
	char string_priority[100] = "";
	long table_calc_numbers_l[70] = {0};
	double table_calc_numbers_d[70] = {0.0};
	char table_calc_ops[70] = {0};
	int d = 0;
	char *pointer_interm = NULL;
	double param_for_functions = 0;
	
	if(strchr(string, '.') != NULL)
		d = 1;
	while(i1 < strlen(string)){
		if(string[i1] != ' '){//ignore spaces
			if(strchr("0123456789*/%+-()", string[i1]) == NULL){//Bad character !
				if(string[i1] >= 'a' && string[i1] <= 'z'){// Test if this is a function
					if(!d){
						param_for_functions = (double) table_calc_numbers_l[i3];
						if(functions(string+i1, &i1, &param_for_functions) == EXIT_FAILURE){
							return EXIT_FAILURE;
						}
						table_calc_numbers_l[i3] = (long) param_for_functions;
					}
					else{
						if(functions(string+i1, &i1, table_calc_numbers_d+i3) == EXIT_FAILURE){
							return EXIT_FAILURE;
						}
					}
					if(i1 < strlen(string))
						table_calc_ops[i3] = string[i1];
					i1++;
					i3++;
				}
				else{
					return EXIT_FAILURE;
				}
			}
			else{			
				if(string[i1] == '('){
					for(i2 = 0 ; string[i1+i2+1] != '\0' && i2 < 99 ; i2++){
						string_priority[i2] = string[i1+i2+1];
						if(string[i1+i2+1] == ')')
							end_priority = i2;
					}
					
					string_priority[end_priority+2] = '\0';
					
					if(i1 == 0){
						table_calc_ops[i1] = string[i1+end_priority+2];
					}
					else{
						table_calc_ops[i1-1] = string[i1+end_priority+2];
					}
					if(!d)
						calculatestring(string_priority, table_calc_numbers_l+i3, NULL);
					else
						calculatestring(string_priority, NULL, table_calc_numbers_d+i3);
					i1+=i2+3;
					i3++;
				}
				else{
					if(!d){
						table_calc_numbers_l[i3] = strtol(string+i1, &pointer_interm, 10);
						table_calc_ops[i3] = *pointer_interm;
					}
					else{
						table_calc_numbers_d[i3] = strtod(string+i1, &pointer_interm);
						table_calc_ops[i3] = *pointer_interm;
					}
					i3++;
					i1=pointer_interm+1-string;
				}
				
				if(table_calc_ops[i3-1] == '\0'){
					break;
				}
			}
		}
		else{
			i1++;
		}
	}
	
	if(!d){
		*total_l = table_calc_numbers_l[0];
		for(i1 = 0 ; i1 < strlen(table_calc_ops) ; i1++){
			switch (table_calc_ops[i1])
			{
			case '+':
				*total_l+=table_calc_numbers_l[i1+1];
				break;
			case '-':
				*total_l-=table_calc_numbers_l[i1+1];
				break;
			case '*':
				*total_l*=table_calc_numbers_l[i1+1];
				break;
			case '/':
				*total_l/=table_calc_numbers_l[i1+1];
				break;
			case '%':
				*total_l%=table_calc_numbers_l[i1+1];
				break;
			}
		}
	}
	else{
		*total_d = table_calc_numbers_d[0];
		for(i1 = 0 ; i1 < strlen(table_calc_ops) ; i1++){
			switch (table_calc_ops[i1])
			{
			case '+':
				*total_d+=table_calc_numbers_d[i1+1];
				break;
			case '-':
				*total_d-=table_calc_numbers_d[i1+1];
				break;
			case '*':
				*total_d*=table_calc_numbers_d[i1+1];
				break;
			case '/':
				*total_d/=table_calc_numbers_d[i1+1];
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}

