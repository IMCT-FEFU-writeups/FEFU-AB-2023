#include <stdio.h>

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	size_t a;
	fscanf(fIn,"%lld",&a);
	double summ = 0;
	double next;
	for(size_t i = 0; i < a; i++){
		fscanf(fIn,"%lf",&next);
		summ+=next;
	}
	fprintf(fOut,"%lf",summ/a);
}
