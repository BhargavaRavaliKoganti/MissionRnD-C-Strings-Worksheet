/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int intPart = (int)number;
	float floatPart = number - intPart;
	int temp;
	int index = 0;
	int flag = 0;
	if (intPart < 0){
		str[index] = '-';
		index++;
		flag = 1;
	}
	if (intPart < 0){
		while (intPart){
			str[index] = (-intPart % 10) + '0';
			intPart /= 10;
			index++;
		}
	}
	else{
		while (intPart){
			str[index] = (intPart % 10) + '0';
			intPart /= 10;
			index++;
		}
	}
	int j = index - 1;
	int i = 0;
	if (flag){
		i = 1;
	}
	while (i < j){
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
	int fPart = 0;
	char *res = '\0';
	if (floatPart != 0){
		for (int x = 0; x < afterdecimal; x++)
			floatPart = floatPart * 10;
		fPart = (int)floatPart;
		str[index] = '.';
		index++;
		int y = index;
		while (fPart != 0){
			if (fPart > 0){
				str[index] = (fPart % 10) + '0';
				index++;
				fPart /= 10;
			}
			else{
				str[index] = (-fPart % 10) + '0';
				index++;
				fPart /= 10;
			}
		}
		int temp;
		for (int x = index - 1; x >= y; x--, y++){
			temp = str[x];
			str[x] = str[y];
			str[y] = temp;
		}
	}
	str[index] = '\0';
}
