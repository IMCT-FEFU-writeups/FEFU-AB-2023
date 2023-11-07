#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int N;
	fscanf(fIn,"%d",&N);
	int *A = calloc(N,4);
	
	for(int *index = A; index < A+N; index++){
		fscanf(fIn,"%d",index);
	}
	fscanf(fIn,"\n");
	int sum = 0;
	char c;
	for(int i = 0; i < N; i++){
		fscanf(fIn,"%c",&c);
		sum += A[i]*(c=='+'? 1:0);
	}
	fprintf(fOut,"%d\n",sum);
}
