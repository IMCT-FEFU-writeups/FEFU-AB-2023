#include <stdio.h>
#include <string.h>

int main() {
  int a;
  char answ[8];
  scanf("%i", &a);

  if (a % 3 == 0)
    strcat(answ, "Fizz");
  if (a % 5 == 0)
    strcat(answ, "Buzz");

  printf("%s\n", answ);
  return 0;
}
