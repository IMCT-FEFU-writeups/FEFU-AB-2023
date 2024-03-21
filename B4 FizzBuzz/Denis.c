#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	if(a%3==0){
		printf("Fizz");
	}
	if(a%5==0){
		printf("Buzz");
	}
	printf("\n");

	return 0;
}
