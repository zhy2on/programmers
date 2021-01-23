#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct direct {
	int u, d, r, l;
}Direct;
int isAlreadyPass(int* start, int* end) {
	if(*start) return 1;
	*start = *end = 1;
	return 0;
}
int solution(const char* dirs) {
	int answer = 0, x, y;
	char c;
	Direct dots[11][11], *start, *end;

	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) {
			start = dots[i] + j;
			start->u = start->d = start->r = start->l = 0;
		}
	}

	x = y = 0;
	for(int i = 0; i < strlen(dirs); i++) {
		c = dirs[i];
		start = dots[x + 5] + (y + 5);

		if(c == 'U') {
			if(y == 5) continue;
			y++;
			end = dots[x + 5] + (y + 5);
			if(isAlreadyPass(&(start->u), &(end->d))) continue;
		}
		else if(c == 'D') {
			if(y == -5) continue;
			y--;
			end = dots[x + 5] + (y + 5);
			if(isAlreadyPass(&(start->d), &(end->u))) continue;
		}
		else if(c == 'R') {
			if(x == 5) continue;
			x++;
			end = dots[x + 5] + (y + 5);
			if(isAlreadyPass(&(start->r), &(end->l))) continue;
		}
		else { //'L'
			if(x == -5) continue;
			x--;
			end = dots[x + 5] + (y + 5);
			if(isAlreadyPass(&(start->l), &(end->r))) continue;
		}
		answer++;
	}

	return answer;
}
