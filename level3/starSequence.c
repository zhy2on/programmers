//스타수열ver1. 오류나는 코드.... 조합해서 스타수열인지 확인
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int isStar(int x[], int len){
	int inter[2] = {x[0], x[1]}, i, inter_len = 2;
	for(i = 2; i <= len-2; i += 2){
		if(inter_len == 2){
			if((inter[0] != x[i]) && (inter[0] != x[i+1])){
				inter_len--;
				inter[0] = inter[1];
			}
			if((inter[1] != x[i]) && (inter[1] != x[i+1])){
				inter_len--;
				if(inter_len == 0) return 0;
			}
		}
		else if(inter_len == 1){
			if(inter[0] != x[i] && inter[0] != x[i+1]) return 0;
		}
	}
	return 1;
}
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int* flag){
	if(*flag == 1) return;

	if(index == r){
		if(isStar(data, r)) *flag = 1;
	}

	for(int i=start; i<=end && end-i+1 >= r-index; i++){
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r, flag);
	}
}
int executeCombi(int arr[], int n, int r){
	int data[r], flag = 0;
	combinationUtil(arr, data, 0, n-1, 0, r, &flag);
	return flag;
}
int solution(int a[], size_t a_len) {
	int  r = a_len;

	if(a_len == 1) return 0;
	if(a_len % 2 != 0) a_len--;

	while(r / 2){ //r이 2가 될 때까지 a_len C r 이 star수열이 되는지 확인
		if(executeCombi(a, a_len, r)) return r;
		r -= 2;
	}

	return 0;
}
