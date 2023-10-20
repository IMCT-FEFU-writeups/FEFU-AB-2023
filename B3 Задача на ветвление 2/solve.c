#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define if_even(a) (a % 2 ? 0 : a)

int main() {
  FILE *fin, *fout;
  long long a, b, c, d;
  short is_even, is_positive;
  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w+");
  fscanf(fin, "%lld %lld %lld %lld", &a, &b, &c, &d);

  is_even = !((a + b + c + d) % 2);
  is_positive = (a * b * c * d) >= 0;

  if (is_positive) {
    if (is_even)
      fprintf(fout, "%lld", max(a, max(b, max(c, d))));
    else
      fprintf(fout, "%lld", min(a, min(b, min(c, d))));
  } else
    fprintf(fout, "%lld", if_even(a) + if_even(b) + if_even(c) + if_even(d));
  
