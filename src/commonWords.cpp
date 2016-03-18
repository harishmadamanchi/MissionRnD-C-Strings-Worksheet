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

void xstrcpy(char **result, int len, char *str, int index)
{
	int i;
	for (i = 0; str[index] != ' '&&str[index] != '\0'; index++, i++)
		result[len][i] = str[index];
	result[len][i] = '\0';
}
char ** commonWords(char *str1, char *str2) {
	int i, j, index, k;
	char **Arr;
	if (str1&&str2)
	{
		Arr = (char **)malloc(sizeof(char*)* SIZE);
		for (index = 0; index < 10; index++)
			Arr[index] = (char *)malloc(sizeof(char)* SIZE);
		for (index = k = 0; str1[index] != '\0'; index++)
		{
			if ((index == 0 || str1[index - 1] == ' ') && str1[index] != ' ')
			{
				for (j = 0, i = index; str2[j] != '\0'&&str1[i] != '\0'; j++)
				{
					if ((str2[j] == ' ' || str2[j + 1] == '\0') && ((str1[i] == ' ' || str1[i + 1] == '\0') || (str1[i] == str2[j] && str2[j + 1] == '\0'&&str1[i + 1] == ' ')))
					{
						xstrcpy(Arr, k, str1, index);
						k++;
					}
					if (str1[i] == str2[j])
						i++;
					else
						i = index;
				}
			}
		}
		if (k != 0)
			return Arr;
		return NULL;
	}
	return NULL;
}