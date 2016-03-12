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
#include<stdlib.h>


void number_to_str(float number, char *str,int afterdecimal){
	int count = 0, flag = 0;
	int  numpart, len, tlen;
	float decimal;
	if (number < 0){
		number = number*-1;
		flag = 1;
	}
	numpart = (int)number;
	decimal = number - numpart;
	int temp, temp1, ctemp, decimal1;
	temp = numpart;
	while (temp != 0){
		count++;
		temp = temp / 10;
	}
	ctemp = count;
	for (int i = 0; i < afterdecimal; i++){
		decimal = decimal * 10;
	}
	decimal1 = (int)decimal;
	len = count + 1 + afterdecimal;
	if (flag == 0){
		while (numpart != 0){
			temp1 = numpart % 10;
			str[count - 1] = temp1 + '0';
			numpart = numpart / 10;
			count--;
		}
	}
	else{
		str[0] = '-';
		len = len + 1;
		while (numpart != 0){
			temp1 = numpart % 10;
			str[count] = temp1 + '0';
			numpart = numpart / 10;
			count--;
		}
	}
	if (afterdecimal > 0){
		if (flag == 0){
			str[ctemp] = '.';
			tlen = len;
		}
		else{
			str[ctemp + 1] = '.';
			tlen = len;
		}
		while (decimal1 != 0){
			temp1 = decimal1 % 10;
			str[len - 1] = temp1 + '0';
			decimal1 = decimal1 / 10;
			len--;
		}
		str[tlen] = '\0';
	}
	else{
		if (flag == 1){
			str[ctemp + 1] = '\0';
		}
		else{
			str[ctemp] = '\0';
		}
	}
}
