#include <stdio.h>
int main(){
	int N;
	char c;
	scanf("%d %c",&N, &c);
	
	if(c == 'b'){
		N&=0xFF;
	}
	else if(c=='g'){
		N&=0xFF00;
	}
	else if(c == 'r'){
		N&=0xFF0000;
	}
	printf("%d",N);
}
