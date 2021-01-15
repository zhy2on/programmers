#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool solution(const char* s) {
	int top = -1;
	char* stack = (char*)malloc((strlen(s)+1) * sizeof(char));

	while(*s){
		if(*s == '(') stack[++top] = *s;
		else {
			if(top == -1) return false;
			else top--;
		}
		s++;
	}

	free(stack);

	if(top == -1) return true;
	else return false;
}
