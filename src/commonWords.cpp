/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char word1[50][10];
	char word2[50][10];
	char **result = (char**)malloc(sizeof(char *) * SIZE);
	for (int i = 0; i < 10; ++i) {
		result[i] = (char *)malloc(sizeof(char) * SIZE);
	}
	int x = 0, y = 0;
	int u = 0, v = 0; 
	int p = 0, q = 0;
	for(int i = 0; str1[i] != '\0'; i++){
		if(str1[i] == ' '){
			word1[x][y] = '\0';
			x++;
			y = 0;
		}
		else{
			p = 1;
			word1[x][y] = str1[i]; 
			y++;
		}
	}
	word1[x][y] = '\0';
	x++;	
	for(int j = 0; str2[j] != '\0'; j++){
                if(str2[j] == ' '){
                        word2[u][v] = '\0';
						u++;
                        v = 0;
                }
                else{
					q = 1;
                    word2[u][v] = str2[j]; 
                    v++;
                }
        }
	word2[u][v] = '\0';
	u++;
	if (p != 1 || q != 1)
		return NULL;
	int flag = 0;
	int z = 0;
	int g =0;
	int val = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < u; j++){
			z = 0;
			flag = 0;
			while(word1[i][z] != '\0' || word2[j][z] != '\0'){
				if(word1[i][z] != word2[j][z]){
					flag = 1;
					break;
				}
				z++;
			} 
			if(flag == 0 && word1[i][z] == '\0' && word2[j][z] == '\0'){
				z = 0;
				val = 1;
				while(word1[i][z] !='\0'){
					result[g][z] = word1[i][z];
					z++;
				}
				result[g][z] = '\0';
				g++;
			}
		}
	}
	if (val)
		return result;
	return NULL;
}