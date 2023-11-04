#include <stdio.h>
#include <string.h>

#define min(a,b) (a<b? a:b)
#define max(a,b) (a>b? a:b)

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	long long a,b,c,d;
	fscanf(fIn,"%lld %lld %lld %lld",&a, &b, &c, &d);
	if(a*b*c*d>=0){
		if((a+b+c+d)%2==0){
			fprintf(fOut,"%lld",max(a,max(b,max(c,d))));
		}
		else {
			fprintf(fOut,"%lld",min(a,min(b,min(c,d))));
		}
	}
	else{
		fprintf(fOut,"%lld", (a%2==0? a:0) + (b%2==0? b:0) + (c%2==0? c:0) + (d%2==0? d:0));
	}
}
