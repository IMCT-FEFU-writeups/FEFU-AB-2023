#include <stdio.h>

long long nod(long long a, long long b){
	while(a!=0 && b!=0){
		if(a>b){
			a%=b;
		}
		else{
			b%=a;
		}
	}
	return a+b;
}

int main() {
	long long a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld %lld %lld\n", nod(a,b), nod(a,c), nod(b,c));
}
