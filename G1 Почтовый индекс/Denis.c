#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Index{
    char *buffer;
    size_t size;
};

void innit_buffer_to(struct Index *dist,char c){
    if(dist->size>0){
        return;
    }
    dist->buffer = calloc(1,sizeof(char));
    dist->buffer[0] = c;
    dist->size = 1;
}

void try_replace_Index(struct Index* witch,struct Index* src){
    //printf("%s%c\n",src->buffer,c);
    if(src->size==0 || src->buffer[0]=='0'){
        free(src->buffer);
        return;
    }
    if(witch->size==0){
        goto swap;
    }
    if(witch->buffer[0]=='0'){
        goto swap;
    }
    if(witch->size>src->size){
        goto swap;
    }
    if(witch->size==src->size && strcmp(witch->buffer,src->buffer)>0){
        goto swap;
    }
    if(src->buffer){
        free(src->buffer);
    }
    return;
    swap:
        free(witch->buffer);
        witch->buffer = src->buffer;
        witch->size = src->size;
    return;
}

int main(){
    //extern struct Index;
    size_t straigth[] = {6,2,3,2,4,5,4,2,7,4};
    size_t slope[] =    {0,1,1,2,0,0,1,1,0,1};
    int a,b;
    scanf("%d %d",&a,&b);
    if((a == 6 && b == 0) || b > a){
        printf("Wrong\n");
        return 0;
    }
    size_t rows = a+10, cols = b+5;
    struct Index* matrix = calloc(rows*cols,sizeof(struct Index));
    for(size_t k = 0; k < 10;k++){
        innit_buffer_to(&matrix[ straigth[k]*cols + slope[k]],k+48);
    }
    for(size_t row = 0; row < a; row++){
        for(size_t col = 0; col <= b; col++){
            if(matrix[row*cols+col].size>0){
                for(size_t k = 0; k < 10;k++){
                    struct Index* next = malloc(sizeof(struct Index));
                    next->buffer = calloc(matrix[row*cols + col].size+1+5,sizeof(char));
                    strcpy(next->buffer,matrix[row*cols + col].buffer);
                    next->buffer[matrix[row*cols + col].size] = k+'0';
                    next->size=matrix[row*cols + col].size+1;
                    try_replace_Index(matrix + (straigth[k]+row)*cols + slope[k]+col,next);
                    free(next);
                }
                free(matrix[row*cols+col].buffer);
                matrix[row*cols+col].buffer = NULL;
                matrix[row*cols+col].size=0;
            }
        }
    }

    printf("%.*s\n",(int)matrix[a*cols+b].size>0?matrix[a*cols+b].size:5,matrix[a*cols+b].size>0?matrix[a*cols+b].buffer:"Wrong");
}
