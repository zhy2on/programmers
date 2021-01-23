//ver1: 제출시 실패 -> 현재 점 기준으로 u인 상황에서 도착 점은 d가 0이지만 d를 할 경우 이미 지나갔던 길
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct direct {
	int u, d, r, l;
}Direct;
int isAlreadyPass(int* tmp) {
	if(*tmp) return 1;
	*tmp = 1;
	return 0;
}
int solution(const char* dirs) {
	int answer = 0, x, y;
	char c;
	Direct dots[11][11], *tmp;

	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) {
			tmp = dots[i] + j;
			tmp->u = tmp->d = tmp->r = tmp->l = 0;
		}
	}
	x = y = 0;
	for(int i = 0; i < strlen(dirs); i++) {
		c = dirs[i];
		tmp = dots[x + 5] + (y + 5);

		if(c == 'U') {
			if(y == 5) continue;
			y++;
			if(isAlreadyPass(&(tmp->u))) continue;
		}
		else if(c == 'D') {
			if(y == -5) continue;
			y--;
			if(isAlreadyPass(&(tmp->d))) continue;
		}
		else if(c == 'R') {
			if(x == 5) continue;
			x++;
			if(isAlreadyPass(&(tmp->r))) continue;
		}
		else { //'L'
			if(x == -5) continue;
			x--;
			if(isAlreadyPass(&(tmp->l))) continue;
		}
		answer++;
	}

	return answer;
}
