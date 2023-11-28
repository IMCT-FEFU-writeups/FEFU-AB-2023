#include <stdio.h>
#include <math.h>
int main()
{
    FILE *fIn, *fOut;
    fIn = fopen("input.txt","r");
    fOut = fopen("output.txt","w");
    unsigned long long x;
    fscanf(fIn,"%llu", &x);
    int flag = 1;
    do
    {
        unsigned long long prefix_mul = 1;
        flag = 0;
        for(unsigned long long i = pow(10,(int)log10(x)); i > 0; i/=10)
        {
            unsigned long long delitel = (unsigned long long)(x/i)%10;
            prefix_mul*=delitel;
            if(prefix_mul%10 == 0)
            {

                flag = 1;
                x=((unsigned long long)(x/i)+1)*i;
                break;
            }

            else if(x%delitel!=0)
            {
                flag = 1;
                x=(unsigned long long)ceil((double)x/(double)delitel)*delitel;
                break;
            }
        }
    }
    while(flag);
    fprintf(fOut,"%llu",x);
}
