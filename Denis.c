#include <stdio.h>
#include <stdlib.h>
#define max(a,b)((a)>(b)? (a):(b))
size_t binmaxis(unsigned long long *array, size_t max_index, size_t value){
    size_t index = max_index;
    size_t mul = 1;
    while(max_index>=mul && index>0){
        if(array[index-max_index/mul]>value){
            index -= max_index/mul;
        }
        mul*=2;
    }
    while(index > 0 && (array[index-1]>value || array[index-1]==array[index])){
        index--;
    }
    //printf("%d\n",index);
    return index;
}

int main()
{
    size_t N,K;
    scanf("%llu %llu",&N,&K);
    //create array of visitors
    size_t *query = calloc(N,sizeof(size_t));
    size_t max = 0;
    for(size_t i = 0,next; i < N; i++){
        scanf("%llu",&next);
        query[i]=next+K;
        if(i>0){
           query[i]=max(query[i],query[i-1]+K);
        }
        //printf("%llu %llu\n",query[i],binmaxis(query,i,next));
        max=max(max,i-binmaxis(query,i,next));
    }
    printf("%llu",max);
}
