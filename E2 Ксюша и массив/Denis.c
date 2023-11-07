#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int N;
	fscanf(fIn,"%d",&N);
	long long *A = calloc(N,8);
	for(long long *index = A; index < A+N; index++){
		fscanf(fIn,"%lld",index);
	}
	for(int i = 0; i < N; i++){
		int flag = 1;
		for(int j = 0; j < N; j++){
			if(i!=j && A[j]%A[i] != 0){
				flag = 0;
				break;
			}
		}
		if(flag){
			fprintf(fOut,"%lld\n",A[i]);
			return 0;
		}
	}
	fprintf(fOut,"-1\n");
}
