//스타수열 ver3 연결리스트 없이 -> 테스트케이스 오류 2, 14, 15, 28
#include <stdio.h>
#include <stdlib.h>
typedef struct star {
	int len, flag, bfIdx;
}Star;
void initStar(Star* star, int a_len);
void updateLen(Star* star, int curIdx);
void lastUpdate(Star* star, int curIdx);
int solution(int a[], int a_len);	
int main() {
	int a[] = { 3,3,2,2,3,3 };
	int a_len = 6;
	
	printf("%d\n", solution(a, a_len));

	return 0;
}
void initStar(Star* star, int a_len) {
	for(int i = 0; i < a_len; i++) {
		(star + i)->len = 0; 
	}
}
void updateLen(Star* star, int curIdx) {
	int bfIdx = star->bfIdx;

	if(star->len == 0) { //처음 업데이트 되는 경우일 때
		if(curIdx > 0) { star->flag = -1; star->len += 2; }
		else { star->flag = 1; star->len += 2; }
		star->bfIdx = curIdx;
		return;
	}
	
	if(star->flag == -1) { //이전 인덱스가 왼쪽과 묶인 경우
		if(curIdx - bfIdx > 1) { star->flag = -1; star->len += 2; } //왼쪽에 자리가 있는 경우
		else { star->flag = 1; star->len += 2; } //왼쪽에 자리가 없는 경우
	}

	else { //if(star->flag == 1) //이전 인덱스가 오른쪽과 묶인 경우
		if(curIdx == bfIdx + 1) { star->flag = -1; } //현재 인덱스가 이전 인덱스의 오른쪽인 경우
		else if(curIdx - (bfIdx + 1) > 1) { star->flag = -1; star->len += 2; } //왼쪽에 자리가 있는 경우
		else { star->flag = 1; star->len += 2; } //왼쪽에 자리가 없는 경우
	}

	star->bfIdx = curIdx;
}
void lastUpdate(Star* star, int curIdx) { //마지막 원소인 경우 해당 스타배열 기준으로 왼쪽 자리가 남아있는 경우만 len갱신
	int bfIdx = star->bfIdx;

	if(star->flag == -1) {
		if(curIdx - bfIdx > 1) star->len += 2;
	}
	else {
		if(curIdx - (bfIdx + 1) > 1) star->len += 2;
	}
}
int solution(int a[], int a_len) {
	int i, max;
	Star* star;

	if(a_len == 1) return 0;

	//1. a_len만큼 star배열 동적할당 후 초기화
	star = (Star*)malloc(a_len * sizeof(Star));
	initStar(star, a_len);

	//2. a[]돌면서 star[]채우기 이 때 각 리스트의 최대 스타수열 길이 len을 저장
	for(i = 0; i < a_len - 1; i++){
		updateLen(star+a[i], i); 
	}
	lastUpdate(star+a[i], i);

	//3. star[] 돌면서 최대길이 max찾기
	max = star[0].len;
	for(i = 1; i < a_len; i++){
		if(star[i].len > max) max = star[i].len;		
	}
	 
	return max;
}
	
