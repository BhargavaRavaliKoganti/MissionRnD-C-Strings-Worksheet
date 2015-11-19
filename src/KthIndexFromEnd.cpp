/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int index;
	int j;
	int i;
	//char *s = NULL;
	char element = '\0';
	if (str == 0 || K < 0 || str[0] == '\0')
		return element;
	for (i = 0; str[i] != '\0'; i++);
	if (i < K)
		return element;
	for (index = 0, j = K; str[j] != '\0'; index++, j++);
	element = str[index - 1];
	return element;
}