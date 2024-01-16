#include <stdio.h>  
#include <stdlib.h>  
  
#define max(a, b) ((a > b)?a:b)  
#define lli long long int  
  
lli max_element = 0;  
  
  
int comp (const void * elem1, const void * elem2)   
{  
    int f = *((int*)elem1);  
    int s = *((int*)elem2);  
    max_element = max(max_element, f);  
    max_element = max(max_element, s);  
    if (f > s) return  1;  
    if (f < s) return -1;  
    return 0;  
}  
  
  
lli count_max_queue(lli n, lli t, lli *arr){  
      
    lli now_time = 0;  
    lli left_point = 0, right_point = 0;  
    lli record = 0;  
    while(right_point < n){  
        if (right_point - left_point == 0){  
            now_time = arr[right_point];  
        }  
  
        if (arr[left_point] <= now_time){  
            now_time += t;  
            left_point++;  
            while (arr[right_point] < now_time && right_point < n){  
                right_point++;  
            }  
        }  
        // printf("%d %d %d\n", left_point, right_point, now_time);  
        // for (int i = left_point;i < right_point;i++){  
        //     printf("%d ", my_queue[i]);  
        // }  
        // printf("\n---\n");  
        record = max(record, (right_point - left_point));  
    }  
  
    return record;  
}  
  
  
lli check(lli n, lli t, lli *arr, lli max_queue){  
    lli temp = count_max_queue(n, t, arr);  
    if (temp == -1){  
        return 0;  
    }  
    return (temp < max_queue);  
}  
  
  
int main(){  
    FILE *inp;  
    FILE *out;  
    inp = fopen("input.txt", "r");  
    out = fopen("output.txt", "w");  
      
    lli n, max_queue, res;  
    fscanf(inp, "%lld %lld", &n, &max_queue);  
    lli queue[n];  
    for (lli i = 0; i < n;i++){  
        fscanf(inp, "%lld", &queue[i]);  
    }  
    qsort (queue, sizeof(queue)/sizeof(*queue), sizeof(*queue), comp);  
    // (check(n, t, queue, max_queue))  
    lli l = 1, m, r = max_element+1;  
    while((r - l) > 1){  
        m = (r + l) / 2;  
        // printf("%lld %lld %lld\n", l, m, r);  
        if (check(n, m, queue, max_queue)){  
            l = m;  
        }  
        else{  
            r = m;  
        }  
    }  
    res = l;  
    fprintf(out, "%lld", res);  
    return 0;  
}
