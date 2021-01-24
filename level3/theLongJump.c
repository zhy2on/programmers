//ver2 : 오류- signal: floating point exception (core dumped))
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int factorial(int n) {
	if(n <= 1) return 1; //nC0일 경우를 생각!
	return n * factorial(n - 1);
}
int combination(int n, int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}
long long solution(int n) {
	long long answer = 0;
	int r;
	
	if(n % 2 == 0) {
		r = n / 2;
		n = n / 2;
	}
	else {
		r = n / 2;
		n = n / 2 + 1;
	}
	
	while(r >= 0) {
		answer += combination(n++, r--);
	}
	answer = answer % 1234567;

	return answer;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", solution(n));
	return 0;
}
