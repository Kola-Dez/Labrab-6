#include <stdio.h>
#include <stdlib.h>

int module(int x){
	if(x < 0){
		return -x;
	}
	return x;
}

void printArray(float* A, int n){
	printf("A =");
	for(int c = 0; c < n; c++){
			printf("%*fl", 20, A[c]); 
		}
	printf("\n");
}


void sortRec(float* A, int n){
	for(int j = 0; j < n*2; j++){
		for(int i = 0; i < n; i++){
			if(A[i] > A[i + 1]){
				float tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
			}
		}
	}

	for(int j = 0; j < n*2; j++){
		for(int i = 1; i < n; i++){
			if(module(A[i]) < 1){
				float tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
			}
		}
	}
}



void newArray(int n){
	float* A = (float*)malloc(n);
	for(int c = 0; c < n; c++){
		float static_cats = rand() % 100 - 20;
		A[c] = (float)(rand()%100) / (float)1000 * (float)(rand()%1000 - 500); 
	}

	printArray( A, n);
	sortRec(A,n);

	printf("\n");
	printArray( A, n);

	free(A);
}

int main(){
	int flag = 1;
	while(flag == 1){
		int n;
		printf("n = ");
		scanf("%d", &n);

		newArray(n);

		printf("Next? > 1(yes)/0(no) >> ");
		scanf("%d", &flag);
	}
	return 0;
}
