//ver1 일단 오류나서 시도조차 못 함.. 뭐가 문젤까
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int factorial(int n) {
	if(n <= 1) return n;
	return n * factorial(n - 1);
}
int combination(int n, int r) {
	int tmp = factorial(r) * factorial(n - r);
	tmp = factorial(n) / tmp;
	return tmp;
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
	
	printf("%d %d\n", n, r);
	while(r >= 0) {
		answer += combination(n, r);
		n++; r--;
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
