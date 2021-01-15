#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b){
	char tmp1[9], tmp2[9]; //a,b 붙인 tmp1, b,a 붙인 tmp2를 비교

	strcpy(tmp1, *(char**)a);
	strcat(tmp1, *(char**)b);

	strcpy(tmp2, *(char**)b);
	strcat(tmp2, *(char**)a);

	return -strcmp(tmp1, tmp2);
}
int calc_len(int n){ //n 길이 구하는 calc_len
	int len = 0;
	if(n == 0) return 1;
	while(n != 0){ n /= 10; len++; }
	return len;
}
void convert_char(char* tmp, int n, int len){ //문자열 변환 convert_char
	tmp[len] = '\0';
	for(int i = len - 1; i >= 0; i--){
		tmp[i] = (n % 10) + '0';
		n /= 10;
	}
}
char* solution(int numbers[], size_t numbers_len) {
	char* answer, **tmp;
	int i, j, total_len = 0, len;
	포인터 배열 할당
		tmp = (char**)malloc(numbers_len * sizeof(char*));

	//1. 각 원소 포인터 배열에 문자열로 저장
	for(i = 0; i < numbers_len; i++){        
		len = calc_len(numbers[i]);
		tmp[i] = (char*)malloc((len + 1) * sizeof(char)); //메모리 할당
		convert_char(tmp[i], numbers[i], len); //문자열로 변환
		total_len += len;
	}

	//2. 포인터 배열 정렬
	qsort(tmp, numbers_len, sizeof(char*), compare);

	//3. answer에 저장
	if(tmp[0][0] == '0'){
		answer = (char*)malloc(2 * sizeof(char));
		strcpy(answer, "0");
	}
	else{
		answer = (char*)malloc((total_len + 1) * sizeof(char));
		strcpy(answer, tmp[0]);
		for(i = 1; i < numbers_len; i++) strcat(answer, tmp[i]);
	}    

	//메모리 해제
	for(i=0; i<numbers_len; i++) free(tmp[i]);
	free(tmp);

	return answer;
}
