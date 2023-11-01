#include <stdio.h>
#pragma gcc optimize("Ofast")

/* 
 * Dont use go to they said...
 */
int main() {
  FILE* in = fopen("input.txt", "r");
  FILE* out = fopen("output.txt", "w+");
  long long n;
  fscanf(in , "%lld", &n);
  long long a[n], divider;
  
  for (int i = 0; i < n; i++)
    fscanf(in, "%lld", &a[i]);
  
  for (int i = 0; i < n; i++) {
    divider = a[i];
    
    for (int j = 0; j < n; j++) {
      if (a[j] % divider != 0)
        goto br;
    }
    fprintf(out, "%lld", divider);
    return 0;
    br:
  }
  fprintf(out, "-1");
  return 0;
}
