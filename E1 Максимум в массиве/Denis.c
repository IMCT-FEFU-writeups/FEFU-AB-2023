#include <stdio.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int n;
	fscanf(fIn,"%d",&n);
	
	int min;
	fscanf(fIn,"%d",&min);
	
	for(int i = 1,next = 0; i < n; i++){
		fscanf(fIn,"%d",&next);
		min = min>next? min:next;
	}
	fprintf(fOut,"%d",min);
}
