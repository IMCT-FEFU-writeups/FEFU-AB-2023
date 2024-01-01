#include <stdio.h>
#include <math.h>
#define max(a,b)(a>b?(a):(b))
int main(){
    char *stack = calloc(100001,sizeof(char));
    int *stack_cnt = calloc(100001,sizeof(int));
    int size = 0,size_cnt = 1;
    char buff[100000];
    gets(buff);
    for(size_t i = 0; buff[i]!='\0'; i++){
        char c = buff[i];
        if(c=='('||c=='['||c=='{'){
            stack_cnt[size_cnt]=0;
            size_cnt++;
            stack[size++]=c;
        }
        else{
            if((stack[size-1]=='(' && c==')') || stack[size-1]==c-2){
                stack_cnt[--size_cnt]++;
                stack_cnt[size_cnt-1] = max(stack_cnt[size_cnt],stack_cnt[size_cnt-1]);
                size--;
            }
            else{
                goto broken;
            }
        }
        /*
        printf("%c ",c);
        for(int i = 0; i < 5; i++){
            printf("%d ",stack_cnt[i]);
        }
        printf("\n");
        */
    }
    if(size>0){
        goto broken;
    }
    printf("%d\n",stack_cnt[0]);
    return 0;
    broken:
        puts("-1\n");
    return 0;
}
