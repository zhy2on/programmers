//ver3
typedef struct sol{
	int* a;
	int* b;
}Sol;
#include <stdio.h>
#include <stdlib.h>
int solution(int a[], int a_len);
int main(){
	int a[] = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
	int a_len = 10;
	
	printf("%d\n", solution(a, a_len));

	return 0;
}
int compare(const void* a, const void* b) {

}
void initSol(Sol* sol, int a[], int a_len) {
	sol->a = (int*)malloc(a_len * sizeof(int));
	sol->b = (int*)malloc(a_len * sizeof(int));
	for(int i = 0; i < a_len; i++) {
		sol->a[i] = a[i];
		sol->b[i] = i;
	}
}
int solution(int a[], int a_len) {
	Sol sol;
	initSol(&sol, a, a_len);


}
