#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	
	int N,M;
	fscanf(fIn,"%d",&N);
	long long *A = calloc(N+1,sizeof(long long));
	long long next;
	for(int i = 1 ;i <= N; i++){
		fscanf(fIn,"%lld",&next);
		A[i] = A[i-1] + next;
	}
	fscanf(fIn,"%d",&M);
	int l,r;
	for(int i = 0; i < M; i++){
		fscanf(fIn,"%d %d",&l,&r);
		fprintf(fOut,"%lld ",A[r]-A[l-1]);
	}
	return 0;
}
