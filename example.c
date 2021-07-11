/* example */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "michiru.h"

int main (int argc, char ** argv) {
  int opt;
  while ((opt = getopt(argc, argv, "i:o:")) != 1) {
    switch (opt) {
      case 'i':
        image_info(argv[1]);
        break;
      case 'o':
        image_info(argv[1]);
        break;
    }
  return EXIT_SUCCESS;
  }
}
