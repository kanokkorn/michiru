/* standard libraries */
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/* stb_image */
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

/* function declaration */
void time_sleep(unsigned int);
void get_image_data(const char*);
void image_gray(const char*);

/* 
 * component declaration 
 */
void conv2d(void);

/* main function */
int main(int argc, char *argv[]) {
  printf("<< Michiru - images process with pure C >>\n");
  if (argv[1] == NULL) {
    printf("no image input\n");
    exit(EXIT_FAILURE);
  }
  printf("converting image to grayscale\n"); 
  image_gray(argv[1]);
  printf("done...\n");
  return 0;
}

/* sleep in second */
void time_sleep(unsigned int sleepVal) {
  int millisec = 1000 * sleepVal;
  clock_t start_time = clock();
  while (clock() < start_time + millisec);
}

/* get image data */
void get_image_data(const char* image_file) {
  int width, height, channel;
  unsigned char *img = stbi_load(image_file, &width, &height, &channel, 0);
  if (img == NULL) {
    printf("Can't open image\n");
    exit(EXIT_FAILURE);
  }
  printf(
      "Image loaded!\n%s has %d px width, %d px height and %d channel\n",
       image_file, width, height, channel
      );
}

/* blur image */
void image_blur(const char* image_file) {
  const char *fname = "image_blur.jpg";
  int x, y, comps, blur_chan;
  unsigned char *img = stbi_load(image_file, &x, &y, &comps, 4);
  size_t image_size = x * y * comps;
  if (comps == 4) {
    blur_chan = 2;
  } else {
    blur_chan = 1;
  }
  size_t blur_image_size = x * y * blur_chan;
  unsigned char *blur_img = malloc(blur_image_size);
  if(blur_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  stbi_write_jpg(fname, x, y, blur_chan, blur_img, 100);
  stbi_image_free(img); stbi_image_free(blur_img);
}

/* convert to grayscale */
void image_gray(const char* image_file) {
  const char *fname = "image_gray.jpg";
  int x, y, comps, gray_chan;
  unsigned char *img = stbi_load(image_file, &x, &y, &comps, 4);
  size_t image_size = x * y * comps;
  if (comps == 4) {
    gray_chan = 2;
  } else {
    gray_chan = 1;
  }
  size_t gray_img_size = x * y * gray_chan;
  unsigned char *gray_img = malloc(gray_img_size);
  if(gray_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  for(unsigned char *p = img, *pg = gray_img; p != img + image_size;
      p += comps, pg += gray_chan) {
    *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
    if(comps == 4) {
      *(pg + 1) = *(p + 3);
    }
  }
  stbi_write_jpg(fname, x, y, gray_chan, gray_img, 100);
  stbi_image_free(img); stbi_image_free(gray_img);
}

/*
 *  component 
 */

void conv2d(void) {
  const float *kernel[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
}
