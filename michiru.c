#include "michiru.h"

void image_info (const char* image_file, img_data *img_data) {
  unsigned char *img = stbi_load(
      image_file, &img_data->width, 
      &img_data->height, &img_data->channel, 0
      );
  if (img == NULL) {
    printf("\nCan't open image\n");
    exit(EXIT_FAILURE);
  }
  printf(
      "\nImage loaded!\n%s has %d px width, %d px height and %d channel\n",
       image_file, img_data->width, img_data->height, img_data->channel
      );
}

void image_blur (const char* image_file, img_data *img_data) {
  const char *fname = "image_blur.jpg";
  int blur_chan;
  unsigned char *img = stbi_load(
      image_file, &img_data->width, 
      &img_data->height, &img_data->channel, 4
      );
  size_t image_size = img_data->width * img_data->height * img_data->channel;
  blur_chan = (img_data->channel == 4) ? 2 : 1;
  size_t blur_image_size = img_data->width * img_data->height * blur_chan;
  unsigned char *blur_img = malloc(blur_image_size);
  if (blur_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  stbi_write_jpg(
      fname, img_data->width, img_data->height,
      blur_chan, blur_img, 100
      );
  stbi_image_free(img);
  stbi_image_free(blur_img);
}

/* support PNG only */
void image_gray (const char* image_file, img_data *img_data) {
  const char *fname = "image_gray.jpg";
  int gray_chan;
  unsigned char *img = stbi_load(
      image_file, &img_data->width,
      &img_data->height, &img_data->channel, 4
      );
  size_t image_size = img_data->width * img_data->height * img_data->channel;
  gray_chan = (img_data->channel >= 4) ? 2 : 1;
  size_t gray_img_size = img_data->width * img_data->height * gray_chan;
  unsigned char *gray_img = malloc(gray_img_size);
  if (gray_img == NULL) {
    printf("Unable to allocate mem for image.\n");
    exit(EXIT_FAILURE);
  }
  for (unsigned char *p = img, *pg = gray_img; p != img + image_size;
      p += img_data->channel, pg += gray_chan) {
    *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
    if (img_data->channel >= 4) {
      *(pg + 1) = *(p + 3);
    }
  }
  stbi_write_jpg(
      fname, img_data->width,
      img_data->height, gray_chan,
      gray_img, 100
      );
  stbi_image_free(img);
  stbi_image_free(gray_img);
}
