/*
 * This code is based on 1, 2, 3 dimention elipce,
 * that belongs to Z_0 only if completion of system with
 * 1,2,3 fishes exists
 */
#include <math.h>
#include <stdio.h>

int main() {
  long long n;
  double x1, x2, x3;
  scanf("%lld", &n);

  x1 = (1 + sqrt(1 + 8 * n)) / 2;
  if (x1 == (long long)x1) {
    printf("1\n");
    return 0;
  }

  for (x1 = 1; x1 <= (long long)(-1 + sqrt(8 * n + 2)) / 2; x1++) {
    x2 = (-1 + sqrt(1 + 8 * n - 4 * x1 * x1 - 4 * x1)) / 2;
    if (x2 == (long long)x2) {
      printf("2\n");
      return 0;
    }
  }

  printf("3\n");
  return 0;
}
