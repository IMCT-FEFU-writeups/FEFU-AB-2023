#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	
	int N;
	fscanf(fIn,"%d",&N);
	int *H = calloc(2001,sizeof(int));
	
	int next;
	for(int i = 0; i < N; i++){
		fscanf(fIn, "%d", &next);
		H[next+1000]++;
	}
	fclose(fIn);
	fOut = fopen("output.txt","w");
	for(int i = 0; i < 2001; i++){
		if(H[i]>0){
			fprintf(fOut,"%d %d\n",i-1000,H[i]);
		}
	}
	fclose(fOut);
	free(H);
}
