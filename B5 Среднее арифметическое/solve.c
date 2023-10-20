#include <stdio.h>

int main() {
  FILE *inFile, *outFile;
  long long len;
  double temp, answ = 0;
  inFile = fopen("input.txt", "r");
  outFile = fopen("output.txt", "w+");
  fscanf(inFile, "%lld", &len);

  if (len <= 0) {
    fprintf(outFile, "0");
  }
  for (int i = 0; i < len; i++) {
    fscanf(inFile, "%lf", &temp);
    answ += temp;
  }
  fprintf(outFile, "%lf", answ / len);
  return 0;
}
