/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
#include <stdlib.h>

void strreverse(char *, int, int);


void str_words_in_rev(char *input, int len){
	int i = 0, j = 0, count = 0, k = 0;
	strreverse(input, 0, len - 1);
	while (input[k] != '\0'){
		if (input[k] == ' '){
			count++;
		}
		k++;
	}
	if (count == 0){
		strreverse(input, 0, len - 1);
	}
	else{
		while (input[j] != '\0'){
			if (input[j] == ' ' && input[j + 1] != ' '){
				i = j + 1;
			}
			else if (input[j + 1] == ' '){
				strreverse(input, i, j);
				i = j + 1;
			}
			else if (input[j + 1] == '\0'){
				strreverse(input, i, j);
			}
			j++;
		}
	}
}

void strreverse(char *input, int intial, int end){
	int i, j;
	char temp;
	for (i = intial, j = end; i <= j; i++, j--){
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
}