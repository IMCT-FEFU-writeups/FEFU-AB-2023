#include <stdio.h>


int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");

	long long N,M,K;
	fscanf(fIn,"%lld %lld %lld", &N, &M, &K);

	if(K==4 || K==13){
		fprintf(fOut,"-1\n");
		return 0;
	}
	if(K>=13){
		K-=2;
	}
	else if(K>=4){
		K--;
	}
    long long unreal_floor = (K)/M + (K)%M>0;

	if(unreal_floor>N){
		fprintf(fOut,"-1\n");
		return 0;
	}
	if(unreal_floor>=4){
		unreal_floor++;
	}
	if(unreal_floor>=13+1){
		unreal_floor++;
	}

	fprintf(fOut,"%lld", unreal_floor);
	return 0;
}
