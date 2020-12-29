#include "michiru.h"

enum {prog, func, imgp};
enum {info, gray, blur, edge, avrg, size, fcol};

int main (int argc, char *argv[]) {
  if (argc == 1 && argv[func] == NULL) {
    printf("\n<<-- Michiru - Images processing with C language -->>\n");
    printf("\nUsage: ./michiru [filename] [function]\n"
           "\nFunction: info - display image width, height and color channel\n"
           "          gray - convert image to grayscale and save to image_gray\n"
           "          blur - blur image with Gaussian filter wtih 3x3 kernel size\n"
           "          edge - find edge in an image\n"
           "          avrg - average color of an image\n"
           "          size - resize an image\n"
           "          fcol - find color in an image\n"
           );
  } else if ((argc >= 1 && argc <= 3) && argv[func] == NULL) {
    printf("no function input\n");
    exit(EXIT_FAILURE);
  } else if ((argc >= 1 && argc <= 3) && argv[func] != NULL && argv[imgp] != NULL) {
    if (strcmp("gray", argv[func]) == 0) {
      printf("\nconverting image to grayscale\n"); 
      image_gray(argv[imgp]);
      printf("done...\n");
    } else if (strcmp("blur", argv[func]) == 0) { 
      printf("\napplying gaussian filter to image\n"); 
      printf("done...\n");
    } else if (strcmp("info", argv[func]) == 0) { 
      printf("\ndisplaying image info\n"); 
      image_info(argv[imgp]);
    } else {
      printf("\nunknown function or not implement yet\n");
    }
    exit(EXIT_SUCCESS);
  } else if ((argc >= 1 && argc <= 3) && argv[func] != NULL && argv[imgp] == NULL) {
    printf("\nUnknown function!\n");
  } else {
    printf("\nUnknown command!\n");
  }
  return 0;
}

void image_info (const char* image_file) {
  int width, height, channel;
  unsigned char *img = stbi_load(image_file, &width, &height, &channel, 0);
  if (img == NULL) {
    printf("\nCan't open image\n");
    exit(EXIT_FAILURE);
  }
  printf(
      "\nImage loaded!\n%s has %d px width, %d px height and %d channel\n",
       image_file, width, height, channel
      );
}

void image_blur (const char* image_file) {
  const char *fname = "image_blur.jpg";
  int x, y, comps, blur_chan;
  unsigned char *img = stbi_load(image_file, &x, &y, &comps, 4);
  size_t image_size = x * y * comps;
  blur_chan = (comps == 4) ? 2:1;
  size_t blur_image_size = x * y * blur_chan;
  unsigned char *blur_img = malloc(blur_image_size);
  if (blur_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  stbi_write_jpg(fname, x, y, blur_chan, blur_img, 100);
  stbi_image_free(img);
  stbi_image_free(blur_img);
}

/* convert to grayscale */
void image_gray (const char* image_file) {
  const char *fname = "image_gray.jpg";
  int x, y, comps, gray_chan;
  unsigned char *img = stbi_load(image_file, &x, &y, &comps, 4);
  size_t image_size = x * y * comps;
  gray_chan = (comps == 4) ? 2:1;
  size_t gray_img_size = x * y * gray_chan;
  unsigned char *gray_img = malloc(gray_img_size);
  if (gray_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  for (unsigned char *p = img, *pg = gray_img; p != img + image_size;
      p += comps, pg += gray_chan) {
    *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
    if (comps == 4) {
      *(pg + 1) = *(p + 3);
    }
  }
  stbi_write_jpg(fname, x, y, gray_chan, gray_img, 100);
  stbi_image_free(img);
  stbi_image_free(gray_img);
}
