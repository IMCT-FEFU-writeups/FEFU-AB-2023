#include <stdio.h>
#include <math.h>

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	double a, b, c;
	fscanf(fIn,"%lf %lf %lf", &a, &b, &c);
	
	double D = b*b - 4*a*c;
	if(a==0){
		if(b==0){
			fprintf(fOut,"-1");
			return 0;
		}
		fprintf(fOut,"%.4lf %.4lf", -c/b , -c/b);
		return 0;
	}
	
	if(D<0){
		fprintf(fOut,"-1");
		return 0;
	}
	fprintf(fOut,"%.4lf %.4lf", (-b+sqrt(D))/2/a, (-b-sqrt(D))/2/a);
}
