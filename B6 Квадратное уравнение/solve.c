#include <math.h>
#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main() {
  FILE *inFile, *outFile;
  double a, b, c, d, x1, x2;
  inFile = fopen("input.txt", "r");
  outFile = fopen("output.txt", "w+");
  fscanf(inFile, "%lf %lf %lf", &a, &b, &c);
  if (a == 0) {
    if (b == 0) {
    fprintf(outFile, "-1\n");
    return 0;
    }
    x1 = c / (-1 * b);
    fprintf(outFile, "%lf %lf\n", x1, x1);
    return 0;
  }
  d = b * b - 4 * a * c;
  if (d < 0) {
    fprintf(outFile, "-1\n");
    return 0;
  }
  x1 = (-1 * b + sqrt(d)) / (2 * a);
  x2 = (-1 * b - sqrt(d)) / (2 * a);
  fprintf(outFile, "%lf %lf\n", max(x1, x2), min(x1, x2));
}
