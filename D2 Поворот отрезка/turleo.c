#include <stdio.h>
#include <math.h>

/*
 * We are going to use formulas from https://en.wikipedia.org/wiki/Rotation_(mathematics)
 */

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w+");
    double xa, ya, xb, yb, xo, yo, b;
    fscanf(fin, "%lf %lf %lf %lf %lf %lf %lf",
            &xa, &ya, &xb, &yb, &xo, &yo, &b);

    /*
     * first of all, we need to convert our angle to radians 
     * because trigonometric functions in c requires radians
     */
    b = (b * M_PI) / 180;

    /*
     * after that we need to move our points in the way 
     * that our rotation point became (0, 0)
     */
    xa -= xo;
    ya -= yo;
    xb -= xo;
    yb -= yo;

    /*
     * now we will apply formulas
     */
    int xt = xa;
    int yt = ya;
    xa = xt * cos(b) - yt * sin(b);
    ya = xt * sin(b) + yt * cos(b);

    xt = xb;
    yt = yb;
    xb = xt * cos(b) - yt * sin(b);
    yb = xt * sin(b) + yt * cos(b);

    /*
     * and add numbers, substracted on lines 24-27
     */
    xa += xo;
    ya += yo;
    xb += xo;
    yb += yo;

    fprintf(fout, "%lf %lf %lf %lf", xa, ya, xb, yb);

    return 0;
}
