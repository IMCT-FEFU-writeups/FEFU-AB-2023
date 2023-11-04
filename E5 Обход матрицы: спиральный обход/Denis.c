#include <stdio.h>
#include <stdlib.h>

void change_dir(int *dir){
	(*dir)++;
	(*dir)%=4;
}

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	int N;
	fscanf(fIn,"%d",&N);
	fclose(fIn);
	int *A = calloc(N*N,4);
	A[0] = 1;
	int row = 0, col = 0;
	int dir = 0; //0-right 1-down 2-left 3-right
	for(int i = 1; i < N*N; i++){
		if(dir == 0){
			if(col+1>=N || A[row*N+(col+1)]!=0){
				change_dir(&dir);
				i--;
			}
			else{
				col++;
				A[row*N+col]=i+1;
			}
		}
		else if(dir == 1){
			if(row+1>=N || A[(row+1)*N+(col)]!=0){
				change_dir(&dir);
				i--;
			}
			else{
				row++;
				A[row*N+col]=i+1;
			}
		}
		else if(dir == 2){
			if(col-1<0 || A[row*N+(col-1)]!=0){
				change_dir(&dir);
				i--;
			}
			else{
				col--;
				A[row*N+col]=i+1;
			}
		}
		else if(dir == 3){
			if(row-1<0 || A[(row-1)*N+(col)]!=0){
				change_dir(&dir);
				i--;
			}
			else{
				row--;
				A[row*N+col]=i+1;
			}
		}
	}
	fOut = fopen("output.txt","w");
	for(row = 0; row < N; row++){
		for(col = 0; col < N; col++){
			fprintf(fOut,"%d ", A[row*N+col]);
		}
		fprintf(fOut,"\n");
	}
	fclose(fOut);
}
