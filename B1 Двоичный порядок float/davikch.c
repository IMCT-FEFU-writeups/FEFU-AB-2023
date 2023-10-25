#include <stdio.h>
#include <math.h>

int main() {
    unsigned int a;
    int output = -127;
    scanf("%f", &a);
    /* Float doesn't allow bitwise operations
    Input is decoded like a float, but the raw bits are put 
    inside unsinged int variable */

    if (a == 0) { printf("%d", 0); return 0; }  // Zero

    if (a >> 23 == 0 || a >> 23 == 256) { printf("%d", -126); return 0; }
    /* Denormalized number: have to output -126 but the reason
    is not clear to me yet */

    for (int i = 0; i <= 7; i++) {
        if (a & 1 << 30 >> i) { output += pow(2, 7 - i); }
    }
    printf("%d", output);
    return 0;
}
