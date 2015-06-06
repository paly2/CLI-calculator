#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "calculatestring.h"

/* TODO: Can use a two-parameters function as parameter. */
int functions(const char *string, int *incrementer, double *result){
	int i = 0, end_priority = 0, i2 = 0, number_char_added = 0;
	char function_name[20] = "";
	char string_priority[20] = "";
	char second_argument[20] = "";
	double total_bracket = 0, total_second_argument = 0;
	for(i = 0 ; string[i] != '(' && string[i] != '\0' ; i++){
		function_name[i] = string[i];
	}
	i++;
	function_name[i] = '\0';
	for(; string[i+1] != '\0' && i < 99 ; i++){
		string_priority[i2] = string[i];
		if(string[i+1] == ')')
			end_priority = i2;
		else if(string[i+1] == ','){
			end_priority = i2;
			break;
		}
		i2++;
	}
	string_priority[end_priority+1] = '\0';
	if(string[i+1] == ','){// If there is a second argument
		i2=0;
		i+=2;
		for(; string[i+1] != '\0' && i < 99 ; i++){
			second_argument[i2] = string[i];
			if(string[i+1] == ')')
				end_priority = i2;
			i2++;
		}
		second_argument[end_priority+1] = '\0';
		if(strchr(second_argument, '.') == NULL){
			strcat(second_argument, ".0");// Because calculatestring must be use double numbers.
			number_char_added+=2;
		}
		if(calculatestring(second_argument, NULL, &total_second_argument) == EXIT_FAILURE)
			return EXIT_FAILURE;
	}
	
	if(strchr(string_priority, '.') == NULL){
		strcat(string_priority, ".0");// Because calculatestring must be use double numbers.
		number_char_added+=2;
	}
	if(calculatestring(string_priority, NULL, &total_bracket) == EXIT_FAILURE)
		return EXIT_FAILURE;
	
	
	if(strcmp(function_name, "abs") == 0)
		*result = fabs(total_bracket);
	else if(strcmp(function_name, "exp") == 0)
		*result = exp(total_bracket);
	else if(strcmp(function_name, "exp2") == 0)
		*result = exp2(total_bracket);
	else if(strcmp(function_name, "log") == 0)
		*result = log(total_bracket);
	else if(strcmp(function_name, "log2") == 0)
		*result = log2(total_bracket);
	else if(strcmp(function_name, "log10") == 0)
		*result = log10(total_bracket);
	else if(strcmp(function_name, "logb") == 0)
		*result = logb(total_bracket);
	else if(strcmp(function_name, "sqrt") == 0)
		*result = sqrt(total_bracket);
	else if(strcmp(function_name, "cbrt") == 0)
		*result = cbrt(total_bracket);
	else if(strcmp(function_name, "hypot") == 0)
		*result = hypot(total_bracket, total_second_argument);
	else if(strcmp(function_name, "sin") == 0)
		*result = sin(total_bracket);
	else if(strcmp(function_name, "cos") == 0)
		*result = cos(total_bracket);
	else if(strcmp(function_name, "tan") == 0)
		*result = tan(total_bracket);
	else if(strcmp(function_name, "asin") == 0)
		*result = asin(total_bracket);
	else if(strcmp(function_name, "acos") == 0)
		*result = acos(total_bracket);
	else if(strcmp(function_name, "atan") == 0)
		*result = atan(total_bracket);
	else if(strcmp(function_name, "sinh") == 0)
		*result = sinh(total_bracket);
	else if(strcmp(function_name, "cosh") == 0)
		*result = cosh(total_bracket);
	else if(strcmp(function_name, "tanh") == 0)
		*result = tanh(total_bracket);
	else if(strcmp(function_name, "asinh") == 0)
		*result = asinh(total_bracket);
	else if(strcmp(function_name, "acosh") == 0)
		*result = acosh(total_bracket);
	else if(strcmp(function_name, "atanh") == 0)
		*result = atanh(total_bracket);
	else if(strcmp(function_name, "pow") == 0)
		*result = pow(total_bracket, total_second_argument);
	else
		return 	EXIT_FAILURE;
	
	if(strlen(second_argument) > 0)// If there is a second argument
		*incrementer+=(int) strlen(function_name) + (int) strlen(string_priority) + (int) strlen(second_argument) + 3 - number_char_added;
	else
		*incrementer+=(int) strlen(function_name) + (int) strlen(string_priority) + 2 - number_char_added;
	return EXIT_SUCCESS;
}
