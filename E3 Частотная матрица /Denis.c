#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b? a:b)

int main() {
	int N,M;
	scanf("%d %d",&N, &M);
	int max = 0;
	long long *A = calloc(N*M,8);
	
	for(long long *index = A; index < A+N*M; index++){
		scanf("%lld",index);
		max = max(max,*index);
	}
	
	long long *B = calloc(N*(max+1),8);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			B[i*(max+1)+A[i*M+j]]++;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < max+1; j++){
			printf("%lld ", B[i*(max+1)+j]);
		}
		printf("\n");
	}
}
