#ifndef michiru_h
#define michiru_h

/* tcc */
#ifdef __TINYC__
#define STBI_NO_SIMD
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* stb_image */
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

typedef struct {
 unsigned int width, height, channel;
}img_data;

void image_info (const char* image_file, img_data *img_data);
void image_blur (const char* image_file, img_data *img_data); 
void image_gray (const char* image_file, img_data *img_data);

#endif /* michiru */
