#include <stdio.h>
int main() {
	long long N,M;
	scanf("%lld %lld", &N, &M);
	long long sum = 0;
	
	long long next, multiplyer;
	if(M == 1){
		for(long long i = 0; i < N; i++){
			scanf("%lld", &next);
			sum+=next*next;
		}
		printf("%lld\n",sum);
		return 0;
	}
	for(long long i = 0; i < N; i++){
		for(long long j = 0; j < M; j++){
			if(j == 0){
				scanf("%lld", &multiplyer);
			}
			else if(j == M-1){
				scanf("%lld", &next);
				sum+=multiplyer*next;
			}
			else{
				scanf("%lld",&next);
			}
		}
	}
	printf("%lld\n",sum);
}
