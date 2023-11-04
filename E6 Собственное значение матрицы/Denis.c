#include <stdio.h>

int main() {
	double a11,a12,a21,lambda;
	scanf("%lf %lf\n%lf X\n%lf",&a11,&a12,&a21,&lambda);
	if(a11==lambda){
		if(a11*lambda+a12*a21-lambda*lambda==0){
			printf("INF\n");
			return 0;
		}
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%lf\n",(a11*lambda+a12*a21-lambda*lambda)/(a11-lambda));
}
