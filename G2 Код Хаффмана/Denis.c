#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct Node *parent,*left,*right;
    float value;
};

char safe_reqursion(struct Node* node, char* pattern, char deep)
{
    if(!node->parent)
    {
        return deep;
    }
    if(node == node->parent->left)
    {
        *(pattern+deep)='0';
        return safe_reqursion(node->parent,pattern,deep+1);
    }
    else
    {
        *(pattern+deep)='1';
        return safe_reqursion(node->parent,pattern,deep+1);
    }
}
void add_lazy_set(struct Node** array, int size, struct Node* value)
{
    //printf("Add %d %d\n",size,value->value);
    if(size>=2)
    {
        for(int i = size-2; i >= 0; i--)
        {
            if(array[i]->value<value->value)
            {
                array[i+1] = array[i];
            }
            else
            {
                array[i+1]=value;
                break;
            }
            if(i == 0)
            {
                array[0] = value;
            }
        }
    }
    else
    {
        array[0] = value;
    }
}

struct Node* create_parent(struct Node *left, struct Node *right)
{
    struct Node* parent = (struct Node*)calloc(1,sizeof(struct Node));
    left->parent=parent;
    right->parent=parent;
    parent->left=left;
    parent->right=right;
    parent->value=left->value+right->value;
    return parent;
}

int main()
{
    FILE *fIn, *fOut;
    fIn = fopen("input.txt","r");
    fOut = fopen("output.txt","w");
    int N;
    fscanf(fIn,"%d",&N);
    struct Node** array = (struct Node**)calloc(N,sizeof(struct Node*));
    struct Node** sorted_array = (struct Node**)calloc(N,sizeof(struct Node*));
    for(int i = 0; i < N; i++)
    {
        struct Node* next = (struct Node*)calloc(1,sizeof(struct Node));
        fscanf(fIn,"%f",&next->value);
        next->parent = NULL;
        next->left = NULL;
        next->right = NULL;
        array[i]=next;
        add_lazy_set(sorted_array,i+1,next);
    }
    struct Node** potentials = (struct Node**)calloc(N,sizeof(struct Node*));
    int potentials_size = 0;
    int sorted_size = N;
    while(sorted_size + potentials_size>=2)
    {
        int min = 10e7;
        if(sorted_size>=2 && sorted_array[sorted_size-1]->value+sorted_array[sorted_size-2]->value < min)
        {
            min = sorted_array[sorted_size-1]->value+sorted_array[sorted_size-2]->value;
        }
        if(potentials_size>=1 && sorted_size >= 1 && potentials[potentials_size-1]->value+sorted_array[sorted_size-1]->value < min)
        {
            min = potentials[potentials_size-1]->value+sorted_array[sorted_size-1]->value;
        }
        if(potentials_size>=2 && potentials[potentials_size-1]->value+potentials[potentials_size-2]->value < min)
        {
            min = potentials[potentials_size-1]->value+potentials[potentials_size-2]->value;
        }
        if(sorted_size >= 2 && sorted_array[sorted_size-1]->value+sorted_array[sorted_size-2]->value <= min)
        {
            add_lazy_set(potentials,++potentials_size,
                         create_parent(sorted_array[sorted_size-1],
                                       sorted_array[sorted_size-2]));
            sorted_size-=2;
        }
        else if(potentials_size>=1 && sorted_size >= 1 && potentials[potentials_size-1]->value+sorted_array[sorted_size-1]->value<=min)
        {
            add_lazy_set(potentials,potentials_size,
                         create_parent(sorted_array[sorted_size-1],
                                       potentials[potentials_size-1]));
            sorted_size--;
        }
        else if(potentials_size>1 && potentials[potentials_size-1]->value+potentials[potentials_size-2]->value<=min)
        {
            add_lazy_set(potentials,potentials_size-1,
                         create_parent(potentials[potentials_size-1],
                                       potentials[potentials_size-2]));
            potentials_size--;
        }
        else
        {
            break;
        }
    }
    free(sorted_array);
    if(potentials_size == 0 || !potentials[0])
    {
        while(1) {}
    }
    //reqursion(potentials[0],pattern,0);
    for(struct Node** index = array; index < array+N; index++)
    {
        char *pattern = (char*)calloc(100,sizeof(char));
        char deep = safe_reqursion(*index,pattern,0);
        strrev(pattern);
            fprintf(fOut,"%.*s\n",deep,pattern);
        free(pattern);
    }
    return 0;
}
