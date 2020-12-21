#include "michiru.h"

int main(int argc, char *argv[]) {
  printf("\n<<-- Michiru - Images processing with pure C -->>\n");
  if (argc == 1 && argv[1] == NULL) {
    printf("\nUsage: ./michiru [filename] [function]\n"
           "Function: gray, blur, edge, etc...\n");
    exit(EXIT_SUCCESS);
  } else if (argc > 1 && argv[1] == NULL) {
    printf("no function input\n");
    exit(EXIT_FAILURE);
  } else if (argc > 2 && argv[1] != NULL && argv[2] != NULL) {
    if (strcmp("gray", argv[1]) == 0) {
      printf("\nconverting image to grayscale\n"); 
      image_gray(argv[2]);
      printf("done...\n");
      exit(EXIT_SUCCESS);
    } else if (strcmp("blur", argv[1]) == 0) { 
      printf("\napplying gaussian filter to image\n"); 
      printf("done...\n");
      exit(EXIT_FAILURE);
    }
  } else {
    printf("\nplease specify image input!\n");
  }
  return 0;
}

void get_image_data(const char* image_file) {
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
