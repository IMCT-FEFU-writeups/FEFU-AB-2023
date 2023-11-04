#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	double Xa,Ya,Xb,Yb,Xo,Yo,β;
	fscanf(fIn,"%lf %lf %lf %lf %lf %lf %lf",&Xa,&Ya,&Xb,&Yb,&Xo,&Yo,&β);
	
	fprintf(fOut,"%.3lf %.3lf %.3lf %.3lf",(Xa-Xo)*cos(β*M_PI/180)-(Ya-Yo)*sin(β*M_PI/180)+Xo,
	                                       (Xa-Xo)*sin(β*M_PI/180)+(Ya-Yo)*cos(β*M_PI/180)+Yo,
	                                       (Xb-Xo)*cos(β*M_PI/180)-(Yb-Yo)*sin(β*M_PI/180)+Xo,
	                                       (Xb-Xo)*sin(β*M_PI/180)+(Yb-Yo)*cos(β*M_PI/180)+Yo);
}
