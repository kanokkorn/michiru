#ifndef MICHIRU_H
#define MICHIRU_H

/* if use tcc, disable SIMD */
#ifdef __TINYC__
#define STBI_NO_SIMD
#endif

/* standard libraries */
#include <stdio.h>
#include <time.h>
#include <math.h>

#ifdef linux 
#include <unistd.h>
#endif

#ifdef _WIN32
#include <stdint.h>
#endif


/* stb_image */
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

typedef struct {
  int x, y, comps;
}img;

/* utilities */
void time_sleep(unsigned int);

/* image processing */
void image_info(const char*);
void image_gray(const char*);
void image_blur(const char*);

/* time.sleep implementation */
void time_sleep(unsigned int sleepVal) {
  int millisec = 1000 * sleepVal;
  clock_t start_time = clock();
  while (clock() < start_time + millisec);
}

#endif
