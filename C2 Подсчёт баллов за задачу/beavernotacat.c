#include <stdio.h>

int main() {
  FILE *in, *out;
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w+");
  long long len;
  fscanf(in, "%lld", &len);
  long long n[len], result = 0;
  char a[len];
  for (long long i = 0; i < len; i++) {
    fscanf(in, "%lld", &n[i]);
  }
  for (long long i = 0; i < len; i++) {
    fscanf(in, " %c", &a[i]);
  }
  
  for (long long i = 0; i < len; i++) {
    if (a[i] == '+')
      result += n[i];
  }
  
  fprintf(out, "%lld", result);
  return 0;
}
