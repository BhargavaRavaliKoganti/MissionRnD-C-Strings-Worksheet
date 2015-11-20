/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i = 0;
	int j = len - 1;
	char temp;
	int k;
	int space = 0;
	for (int x = 0; x < len; x++){
		if (input[x] == ' ')
			space++;
	}
	//printf("%d->space\n", space);
	if (space != 0){
		while (i < j){
			temp = input[j];
			input[j] = input[i];
			input[i] = temp;
			i++;
			j--;
		}
		//printf("%s\n", str);
		i = 0;
		j = 0;
		while (1){
			if (input[j] == ' '){
				k = j;
				j = j - 1;
				while (i < j){
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
					i++;
					j--;
				}
				if (input[k + 1] != ' '){
					i = k + 1;
					j = k + 1;
				}
				else{
					i = k + 2;
					j = k + 2;
				}
			}
			else if (input[j] == '\0'){
				//printf("%d->i %d->j\n", i, j);
				j = j - 1;
				while (i < j){
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
					i++;
					j--;
				}
				break;
			}
			j++;
		}
	}

	return;
}
