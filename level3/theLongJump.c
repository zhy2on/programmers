#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int solution(int n) {
	int ans[2] = {1, 2}, tmp, i;

	if(n == 1) return 1;
	else if(n == 2) return 2;

	for(i = 3; i <= n; i++) {
		tmp = (ans[0] + ans[1]) % 1234567;
		ans[0] = ans[1];
		ans[1] = tmp;
	}

	return tmp;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("ans: %d\n", solution(n));
	return 0;
}
