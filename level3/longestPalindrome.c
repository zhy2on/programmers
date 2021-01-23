#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int count(const char* s, int n) {
	int l , r, len = 0;
	for(l = n-1, r = n+1; l >= 0 && r < strlen(s); l--, r++) {
		if(s[l] == s[r]) len++;
		else break;
	}

	return len * 2 + 1;
}
int solution(const char* s) {
	int answer = 0, tmp;

	for(int i = 0; i < strlen(s); i++) {
		tmp = count(s, i);
		if(tmp > answer) answer = tmp;
	}

	return answer;
}
