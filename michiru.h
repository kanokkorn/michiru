#ifndef MICHIRU_H
#define MICHIRU_H

/* standard libraries */

#include <stdio.h>
#include <unistd.h>
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

/* utilities */

void time_sleep(unsigned int);

/* image processing */

void get_image_data(const char*);
void image_gray(const char*);
void image_blur(const char*);

/* time.sleep implementation */

void time_sleep(unsigned int sleepVal) {
  int millisec = 1000 * sleepVal;
  clock_t start_time = clock();
  while (clock() < start_time + millisec);
}

#endif
