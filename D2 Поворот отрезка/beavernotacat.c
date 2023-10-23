#include <stdio.h>
#include <math.h>

int main() {
  FILE *in, *out;
  double ax, ay, bx, by, ox, oy, b;
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "r");

  fprintf(in, "%lld %lld %lld %lld");
  b = b * 180 / M_PI_2;
  ax = ox + (ax - ox) * cos(b) - (ay - oy) * sin(b);
  ay = oy + (ax - ox) * sin(b) + (ay - oy) * cos(b);
  bx = ox + (bx - ox) * cos(b) - (by - oy) * sin(b);
  by = oy + (bx - ox) * sin(b) + (by - oy) * cos(b);
  fprintf(out, );
  
  return 0;
}
