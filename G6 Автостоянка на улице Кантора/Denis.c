#include <stdio.h>
#include <math.h>
int main(){
    FILE *fIn, *fOut;
    fIn = fopen("input.txt","r");
    fOut = fopen("output.txt","w");
    size_t t;
    fscanf(fIn,"%llu",&t);
    for(size_t i = 0,next = 0; i<t; i++){
        fscanf(fIn,"%d",&next);
        unsigned long long cantor = (unsigned long long)((sqrt(1+8*next)-1)/2);
        unsigned long long y = next-(cantor*cantor+cantor)/2;
        fprintf(fOut,"%llu %llu\n",cantor-y,y);
    }
}
