#include <stdio.h>
int main(){
	unsigned int f;
	int exp;
	scanf("%f",&f);//scan float as his bytecode
	if(f==0){
		printf("0\n");
		return 0;
	}
	exp = (f>>23) & 0xFF;
	exp-=127;
	if(exp <= -127){
		exp +=1;
	}
	printf("%d\n",exp);
}
