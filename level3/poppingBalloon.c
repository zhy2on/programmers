//ver1. 시간초과
#include <stdio.h>
#include <stdlib.h>
// a_len은 배열 a의 길이입니다.
int solution(int a[], int a_len) { 
	int answer = 2, i, j;
	//왼쪽, 오른쪽에서 기준 원소보다 작은 원소가 존재하지 않는 곳이 한 쪽이라도 있으면 true
	for(i = 1; i <  a_len - 1; i++) { 
		for(j = 0; j < i; j++) { //왼쪽 비교
			if(a[j] < a[i]) break;
		}
		if(j == i) {
			answer++; continue;
		}
		for(j = i + 1; j < a_len; j++) { //오른쪽 비교
			if(a[j] < a[i]) break;
		}
		if(j == a_len) answer++;                
	}

	return answer;
}
int main(){
	int a[] = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
	int a_len = 10;
	
	printf("%d\n", solution(a, a_len));

	return 0;
}
