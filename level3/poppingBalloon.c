//ver5: 오류수정 - solution 함수 안 for문 변경
#include <stdio.h>
#include <stdlib.h>
void swapElements(int* p, int* q);
int inPlacePartition(int* a, int* b, int l, int r);
void inPlaceQuickSort(int* a, int* b, int l, int r);
void initB(int b[], int len);
int solution(int a[], int a_len);
int main(){
	int a[] = {9,-1,-5};
	int a_len = 3;
	
	printf("%d\n", solution(a, a_len));

	return 0;
}
void swapElements(int* p, int* q) {
	*p = (*p)^(*q);
	*q = (*p)^(*q);
	*p = (*p)^(*q);
}
int inPlacePartition(int* a, int* b, int l, int r) { //a를 기준으로 b를 정렬 해야 함
	int p, i = l, j = r - 1;
	p = a[b[l]]; //pivot
	swapElements(b+l, b+r); //hide pivot

	while(i <= j) {
		while(i <= j && a[b[i]] <= p) i++;
		while(j >= i && a[b[j]] >= p) j--; /*헷갈리지 말기!*/
		if (i < j) swapElements(b+i, b+j);
	}
	if(i != r) swapElements(b+i, b+r);

	return i; /*빼먹지 말기!*/
}
void inPlaceQuickSort(int* a, int* b, int l, int r) { //a를 기준으로 b를 정렬 해야 함
	int p, q;
	if(l >= r) return;

	p = q = inPlacePartition(a, b, l, r);
	inPlaceQuickSort(a, b, l, p - 1);
	inPlaceQuickSort(a, b, q + 1, r);	
}
void initB(int b[], int len) {
	for(int i = 0; i < len; i++) b[i] = i;
}
int solution(int a[], int a_len) {
	int* b, max, min, i, answer = 0;

	b = (int*)malloc(a_len * sizeof(int));
	initB(b, a_len); //b에 인덱스값을 저장
	
	inPlaceQuickSort(a, b, 0, a_len - 1); //a를 기준으로 b를 내림차순 정렬
	for(i = 0; i < a_len; i++) printf("%d ",b[i]);
	printf("\n");

	max = min = b[0];
	printf("max, min: %d %d\n", max, min);
	for(i = 1; i < a_len - 1; i++) {
		if((max == a_len - 1) && (min == 0)) break;

		printf("%d ", a[i]);
		if(b[i] < min) { answer++; min = b[i]; }
		else if(b[i] > max) { answer++; max = b[i]; }
	}
	printf("\n");
	return answer + 2;
}
