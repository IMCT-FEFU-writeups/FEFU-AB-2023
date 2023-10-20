#include <stdio.h>
#include <string.h>

int main() {
  float num;
  long long nums_exponent;
  scanf("%f", &num);

  memcpy(&nums_exponent, &num, 4);
  nums_exponent = nums_exponent >> 23;
  nums_exponent %= 256; /* Takes the exponent */

  /*
   * !!! STRANGE SHIT !!!
   * Zero must be e = 0 and f = 0; But my cpu says it is
   * 11111110100011110010101100110111000101010110000
   * so here is stupid test
   */
  if (num == 0) {
    printf("0");
    return 0;
  }

  if (nums_exponent == 0)
    nums_exponent = -126; /* Subnorman number, other formula */
  else
    nums_exponent -= 127; /* Normal number */

  printf("%lli\n", nums_exponent);
  return 0;
}
