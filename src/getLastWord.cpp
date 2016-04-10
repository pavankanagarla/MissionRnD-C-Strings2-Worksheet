/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
void reverse(char *str, int len){
	int i;
	int j;
	char temp;
	for (i = 0, j = len - 1; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
int length(char *str){
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}
char * get_last_word(char * str){
	char *result = NULL;
	int len;
	int i;
	int j;
	int flag = 0;
	int temp;
	if (str == NULL)
		return NULL;
	len = length(str);
	reverse(str, len);
	for (i = 0, j = 0; i < len; i++){

		if (str[i] != ' ' && str[i] != '\0'){
			result = (char*)realloc(result, sizeof(int) * (i + 1));
			result[j] = str[i];
			j++;
			if (str[i + 1] == ' ')
				break;
		}
	}
	if (j == 0)
		return "";
	result[j] = '\0';
	reverse(result, j);
	return result;
}