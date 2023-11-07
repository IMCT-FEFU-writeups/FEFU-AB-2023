#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	size_t size;
	fscanf(fIn, "%d",&size);
	long long *A = calloc(size,sizeof(long long));
	
	for(long long *index = A; index < A + size; index++){
		fscanf(fIn, "%lld ",index);
	}
	for(long long *index = A + size - 1; index >= A; index--){
		fprintf(fOut, "%lld ",*index);
	}
}


