#include <stdio.h>
#include <math.h>

int check_1(long long N){
	double x = (1+sqrt(1+8*N))/2;
	if(x==(long long)x){
		return 1;
	}
	return 0;
}

int check_2(long long N){
	for(long long y = 1; y <= (long long)(-1+sqrt(8*N+2))/2;y++){
		double x = (-1+sqrt(1+8*N-4*y*y-4*y))/2;
		if(x==(long long)x){
			return 1;
		}
	}
	return 0;
}

int main(){
	long long N;
	scanf("%lld",&N);
	
	if(check_1(N)){
    printf("1\n");
		return 0;
	}
	
	if(check_2(N)){
    printf("2\n");
		return 0;
	}
	
	printf("3\n");
	return 0;
}
