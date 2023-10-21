#include <stdio.h>

/*
 * Binary Euclid
 */
int gcd(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a == b)
    return a;
  if (a == 1 || b == 1)
    return 1;

  if (!(a % 2) && !(b % 2))
    return gcd(a >> 1, b >> 1) << 1;
  if (!(a % 2) && (b % 2))
    return gcd(a >> 1, b);
  if ((a % 2) && !(b % 2))
    return gcd(a, b >> 1);
  
  if ((a % 2) && (b % 2)) {
    if (a > b)
      gcd((a-b)>>1, b);
    else
    gcd(a, (b-a)>>1);
  }
 
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d ", gcd(a, b));
  printf("%d ", gcd(a, c));
  printf("%d\n", gcd(c, b));
}
