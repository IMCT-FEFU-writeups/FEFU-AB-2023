#include <stdio.h>
#include <stdlib.h>

struct Borders{
    unsigned long long left,right;
};

struct Temple{
    char litera;
    struct Borders borders;
};

struct Borders calculate_intersection(struct Borders first, struct Borders second){
    struct Borders border = {-1,-1};
    if(first.left >= second.left && first.left <= second.right){
        border.left=first.left;
    }
    else if(second.left >= first.left && second.left <= first.right){
        border.left=second.left;
    }
    if(first.right >= second.left && first.right <= second.right){
        border.right=first.right;
    }
    else if(second.right >= first.left && second.right <= first.right){
        border.right=second.right;
    }
    return border;
};

int main(){
    FILE *fIn, *fOut;
    fIn = fopen("input.txt","r");
    fOut = fopen("output.txt","w");
    int N;
    fscanf(fIn,"%d", &N);
    struct Temple* templates = calloc(2*N+1,sizeof(struct Temple));
    int size = 0;
    templates[size].litera = 'Z';
    templates[size].borders.left = 1;
    templates[size].borders.right = 1000000;
    size++;
    char next_litera;
    struct Borders next_borders;

    for(int i = 0; i < N; i++){
        fscanf(fIn,"\n%c %llu %llu",&next_litera,&next_borders.left,&next_borders.right);
        //printf("%c %d %d\n",next_litera,next_borders.left,next_borders.right);
        for(int j = 0; j < size; j++){
            if(templates[j].litera==0){
                continue;
            }
            struct Borders* templ_border = &templates[j].borders;
            struct Borders intersection = calculate_intersection(next_borders,*templ_border);
            if(intersection.left == -1 && intersection.right == -1){
                continue;
            }
            if(intersection.left == templ_border->left && intersection.right == templ_border->right){
                templates[j].litera = 0;
                continue;
            }
            else if(intersection.left == templ_border->left && intersection.right < templ_border->right){
                templ_border->left = next_borders.right+1;
            }
            else if(intersection.left > templ_border->left && intersection.right == templ_border->right){
                templ_border->right = next_borders.left-1;
            }
            else if(intersection.left>templ_border->left && intersection.right < templ_border->right){
                templates[size]=templates[j];
                templ_border->right = intersection.left-1;
                templates[size].borders.left = intersection.right+1;
                size++;
            }
            if(templ_border->right-templ_border->left<0){
                templates[j].litera = 0;
                continue;
            }
        }
        templates[size].litera = next_litera;
        templates[size].borders.left = next_borders.left;
        templates[size].borders.right = next_borders.right;
        size++;
    }
    char *buff = calloc(26,sizeof(char));
    int cnt = 0;
    for(int k = 0; k < size; k++){
        if(templates[k].litera != 0 && !buff[templates[k].litera-65]){
            cnt++;
            buff[templates[k].litera-65]=1;
            //printf("%d %c %d %d\n",k,templates[k].litera,templates[k].borders.left,templates[k].borders.right);

        }
    }
    fprintf(fOut,"%d",cnt);
}
