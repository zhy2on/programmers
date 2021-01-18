//ver2. 퀵소트 직접 구현하려 했던 거
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a[] = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
	int a_len = 10;
	
	printf("%d\n", solution(a, a_len));

	return 0;
}
void swapElements(int* p, int* q) {
	*p = (*p)^(*q);
	*q = (*p)^(*q);
	*p = (*p)^(*q);
}
int inPlacePartition(int* a, int* b, int l, int r) {
	int p, i = l, j = r - 1;
	p = b[l]; //pivot
	swapElements(b+l, b+r); //hide pivot

	while(i <= j) {
		while(i <= j && L[i] <= p) i++;
		while(j >= i && L[i] >= p) j--;
		if (i < j) swapElements(L, i, j);
	}
	if(i != r) swapElements(L, i, r);
}
void inPlaceQuickSort(int* L, int l, int r) {
	int a, b;
	if(l >= r) return;

	a = b = inPlacePartition(L, l, r);
	inPlaceQuickSort(L, l, a - 1);
	inPlaceQuickSort(L, b + 1, r);	
}
void initB(int* b, int len) {
	for(int i = 0; i < len; i++) {
		b[i] = i;
	}
}
int solution(int a[], int a_len) {
	int i, flag, cur;
	int* b = (int*)malloc(a_len * sizeof(int));

	for(i = 0; i < a_len; i++) {
		flag = 0;
		cur = a[i]; //현재 원소가 기준

		
		


	}

}

