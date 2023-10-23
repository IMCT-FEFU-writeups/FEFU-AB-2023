/* Same as C1 */
#include <stdio.h>

int main() {
  FILE *in, *out;
  long long fibi1 = 1, fibi2 = 1, fibi3, i;
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w+");
  fscanf(in, "%lld", &i);
  for (long long j = 1; j <= i; j++) {
    if (j == 1)
      fprintf(out, "0 ");
    if (j == 2 || j == 3)
      fprintf(out, "1 ");
    if (j > 3) {
      fibi3 = fibi1 + fibi2;
      fprintf(out, "%lld ", fibi3);
      fibi1 = fibi2;
      fibi2 = fibi3;
    }
  }
  return 0;  
}
