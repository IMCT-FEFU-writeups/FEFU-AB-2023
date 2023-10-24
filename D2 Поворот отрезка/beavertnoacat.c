#include <stdio.h>
#include <math.h>

int main() {
  double ax, ay, bx, by, ox, oy, b;
  double nax, nay, nbx, nby;
  FILE* in = fopen("input.txt", "r");
  FILE* out = fopen("output.txt", "w+");

  fscanf(in, "%lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &ox, &oy, &b);
  b = b * M_PI / 180;
  nax = ox + ((ax - ox) * cos(b) - (ay - oy) * sin(b));
  nay = oy + ((ax - ox) * sin(b) + (ay - oy) * cos(b));
  nbx = ox + ((bx - ox) * cos(b) - (by - oy) * sin(b));
  nby = oy + ((bx - ox) * sin(b) + (by - oy) * cos(b));
  fprintf(out, "%lf %lf %lf %lf\n", nax, nay, nbx, nby);
  return 0;
}

