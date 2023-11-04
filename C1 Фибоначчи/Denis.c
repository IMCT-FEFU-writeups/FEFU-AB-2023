#include <stdio.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	size_t N;
	fscanf(fIn,"%lld", &N);
	unsigned long long i_1 = 1, i_2 = 0;
	
	for(size_t i = 0; i < N; i++){
		if(i == 0){
			fprintf(fOut,"0 ");
			continue;
		}
		if(i == 1){
			fprintf(fOut,"1 ");
			continue;
		}
		register unsigned long long tmp = i_1+i_2;
		fprintf(fOut,"%llu ",tmp);
		i_2 = i_1;
		i_1 = tmp;
	}
}
