#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int isPrime(int n){
	for(int i = 2; i < n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
	int answer = 0, sum;

	for(int i = 0; i < nums_len; i++){
		for(int j = i+1; j < nums_len; j++){
			for(int k = j+1; k < nums_len; k++){
				sum = nums[i] + nums[j] + nums[k];
				if(isPrime(sum)) answer++;
			}    
		} 
	}

	return answer;
}
