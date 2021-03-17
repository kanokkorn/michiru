/* if use tcc, disable SIMD */
#ifdef __TINYC__
#define STBI_NO_SIMD
#endif

/* standard libraries */
#include <stdio.h>
#include <time.h>
#include <math.h>

/* stb_image */
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

typedef struct {
  int x, y, comps;
}img;

void image_info(const char*);
void image_gray(const char*);
void image_blur(const char*);
