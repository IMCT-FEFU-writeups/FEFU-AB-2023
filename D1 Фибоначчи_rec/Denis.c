#include <stdio.h>

FILE *fIn, *fOut;

int next_fib(int last, int current,int time, int goal){
	extern FILE *fOut;
	if(time>goal){
		return 0;
	}
	fprintf(fOut, "%d ",last+current);
	return next_fib(current,last+current,time+1,goal);
}

int main(){
	extern FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	int N;
	fscanf(fIn,"%d",&N);
	fclose(fIn);
	fOut = fopen("output.txt","w");
	if(N >= 1){
		fprintf(fOut, "0 "); 
	}
	if(N >= 2){
		fprintf(fOut, "1 "); 
	}
	next_fib(0,1,3,N);
}
