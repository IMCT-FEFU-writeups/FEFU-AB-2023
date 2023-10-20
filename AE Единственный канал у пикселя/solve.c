#include <stdio.h>

int main() {
  int pixel_color_raw, pixel_color_form;
  char channel;
  scanf("%d %c", &pixel_color_raw, &channel);

  if (channel == 'r') {
    pixel_color_form = pixel_color_raw >> 16;
    pixel_color_form = pixel_color_form << 16;
  }
  if (channel == 'b') {
    pixel_color_form = pixel_color_raw % 256;
  }
  if (channel == 'g') {
    pixel_color_form = pixel_color_raw >> 8;
    pixel_color_form = pixel_color_form % 256;
    pixel_color_form = pixel_color_form << 8;
  }

  printf("%d", pixel_color_form);
  return 0;
}
