#include <stdio.h>

int main() {
    int n;
    FILE *input, *output;
    input = fopen("input.txt", "r+");
    output = fopen("output.txt", "w+");
    fscanf(input, "%d", &n);

    long long int a[n];

    for (int i = 0; i < n; i++) {    /* Fibonacci does not even need a recursive function */
        if (i == 0 || i == 1)        /* b: Uhm... yes, and? */
            a[i] = i;
        else
            a[i] = a[i-1] + a[i-2];
        
        fprintf(output, "%lld ", a[i]);
    }
    return 0;
}
