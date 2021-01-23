//ver2: 반례 aaaa 답: 4 출력: 3 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int count(const char* s, int n) {
	int l = n - 1, r = n + 1, len = 1;
	if(s[l] != s[r]) {
		if(s[n] == s[r]) { l = n; len = 0; }
		else if(s[n] == s[l]) { r = n; len = 0; }
		else return 1;
	}

	while(l >= 0 && r < strlen(s)) {
		if(s[l] == s[r]) {
			len += 2;
			l--;
			r++;
		}
		else break;
	}

	return len;
}
int solution(const char* s) {
	int answer = 0, tmp;

	for(int i = 0; i < strlen(s); i++) {
		tmp = count(s, i);
		if(tmp > answer) answer = tmp;
	}

	return answer;
}
int main() {
	char s[100];
	scanf("%s", s);
	printf("%d\n", solution(s));
	return 0;
}
