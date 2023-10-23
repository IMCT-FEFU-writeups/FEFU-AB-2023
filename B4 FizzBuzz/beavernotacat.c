#include <stdio.h>
#include <string.h>

int main() {
  int a;
  char answ[8];
  scanf("%i", &a);

  if (a % 3 == 0)
    printf("Fizz");
  if (a % 5 == 0)
    printf("Buzz");
  printf("\n");
  return 0;
}
