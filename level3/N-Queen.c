#include<stdio.h>
#include<stdlib.h>
int isOK(int*choice, int p, int q);
void count(int* choice, int p, int n, int* answer);
int solution(int n);
int main() {
	int n;
	scanf("%d", &n);
	
	printf("sol: %d\n", solution(n));
	return 0;
}
int isOK(int*choice, int p, int q) {
	for(int i = 0; i < p; i++) {
		if(choice[i] == q) return 0;
		if(i - p == choice[i] - q) return 0;
		if(p - i == choice[i] - q) return 0;
	}
	return 1;
}
void count(int* choice, int p, int n, int* answer) {
	int q;

	if(p == n) {
		printf("answer\n");
		for(int i = 0; i < p; i++) printf("%d ", choice[i]);
		printf("\n");
		(*answer)++;
		return;
	}
	for(q = 0; q < n; q++) {
		choice[p] = q;
		if(isOK(choice, p, q)) count(choice, p+1, n, answer);
	}
}
int solution(int n) {
	int answer = 0;
	int* choice = (int*)malloc(n * sizeof(int));

	count(choice, 0, n, &answer);
	
	return answer;
}
