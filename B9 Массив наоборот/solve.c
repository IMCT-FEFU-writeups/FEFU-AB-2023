#include <stdio.h>

int main() {
  FILE *fin, *fout;
  int len;
  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w+");
  fscanf(fin, "%d", &len);
  long long a[len];

  for (int i = 0; i < len; ++i) {
    fscanf(fin, "%lld", &a[i]);
  }
  for (int i = len - 1; i >= 0; --i) {
    fprintf(fout, "%lld ", a[i]);
  }
  return 0;
}
