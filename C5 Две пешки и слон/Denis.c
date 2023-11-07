#include <stdio.h>

#define abss(a)(a<0? -a:a)

int main(){
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int x1,y1,x2,y2;
	fscanf(fIn,"%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1-x2==y1-y2){
		if(x1-x2>1 || x1-x2<-1){
			int delta = (x2-x1)/2;
			fprintf(fOut,"%d %d",x2-delta, y2-delta);
		}
		else{
			fprintf(fOut,"0");
		}
		return 0;
	}
	if(x1-x2==y2-y1){
		if(x1-x2>1 || x1-x2<-1){
			int delta = (x2-x1)/2;
			fprintf(fOut,"%d %d",x2-delta, y2+delta);
		}
		else{
			fprintf(fOut,"0");
		}
		return 0;
	}
	int d = x2-x1+y2-y1;
	if(d%2!=0){
		fprintf(fOut,"0");
	}
	else{
		if(x1+d/2<=0 || y1+d/2<=0 || x1+d/2>8 || y1+d/2>8){
			fprintf(fOut,"%d %d", x2-d/2, y2-d/2);
		}
		else{
			fprintf(fOut,"%d %d", x1+d/2, y1+d/2);
		}
	}
	return 0;
}

