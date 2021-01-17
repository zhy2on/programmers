//스타수열 ver2 연결리스트 구현 해봤던 거 일단 저장
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int idx;
	typedef struct node* next;
}Node;
typedef struct star {
	int len, flag;
	Node* head;
	Node* last;
}Star;
void initStar(Star* star, int len);
Node* getNode(int idx);
void addNodeAfter(Star* star, int idx);
void updateLen(Node* before, int* len, int* flag);
int solution(int a[], int a_len);	
int main() {
	int a[] = { 5, 2, 3, 3, 5, 3 };
	int a_len = 6;
	
	printf("%d\n", solution(a[], a_len));

	return 0;
}
void initStar(Star* star, int len) {
	Star* p;
	for(int i = 0; i < len; i++) {
		p = star + i;
		p->len = 0;
		p->idx = 1;
		p->last = p->head = NULL;
	}
}
Node* getNode(int idx) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	p->idx = idx;
	p->next = NULL;
	return p;
}
void addNodeAfter(Star* star, int idx) {
	if(star->head == NULL) {
		star->last = star->head = getNode(idx);
	}
	else {
		star->last->next = getNode(idx);
		updateLen(star->last, &(star->len), &(star->flag));
		star->last = star->last->next;
	}
}
void updateLen(Node* before, int* len, int* flag) {
	int bfIdx = before->idx, curIdx = before->next->idx;

	if(*flag == -1) { //이전 인덱스가 왼쪽과 묶인 경우
		if(curIdx - bfIdx > 1) { *flag = -1; *len += 2; } //왼쪽에 자리가 있는 경우
		else { *flag = 1; *len += 2; } //왼쪽에 자리가 없는 경우
	}

	else { //if(*flag == 1) //이전 인덱스가 오른쪽과 묶인 경우
		if(curIdx == bfIdx + 1) { *flag = -1; } //현재 인덱스가 이전 인덱스의 오른쪽인 경우
		else if(curIdx - (bfIdx + 1) > 1) { *flag = -1; *len += 2; } //왼쪽에 자리가 있는 경우
		else { *flag = 1; *len += 2; } //왼쪽에 자리가 없는 경우
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
	for(i = 0; i < a_len; i++){
		addNodeAfter(star + a[i]);
	}

	//3. star[] 돌면서 최대길이 max찾기
	max = star[0].len;
	for(i = 1; i < a_len; i++){
		if(star[i].len > max) max = star[i].len;		
	}
	 
	return max;
}
	
