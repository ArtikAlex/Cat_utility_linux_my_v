#include "s21_cat.h"

void parser(int argc, char *argv[], key *options) {
  int res;
  int option_index;
  static struct option long_keys[] = {{"number-nonblank", 0, 0, 'b'},
                                      {"squeeze-blank", 0, 0, 's'},
                                      {"number", 0, 0, 'n'},
                                      {0, 0, 0, 0}};
  while ((res = getopt_long(argc, argv, "+benstvTE", long_keys,
                            &option_index)) != -1) {
    switch (res) {
      case 'b': {
        options->b = 1;
        break;
      }
      case 'e': {
        options->e = 1;
        options->v = 1;
        break;
      }
      case 'E': {
        options->e = 1;
        break;
      }
      case 'n': {
        options->n = 1;
        break;
      }
      case 's': {
        options->s = 1;
        break;
      }
      case 't': {
        options->t = 1;
        options->v = 1;
        break;
      }
      case 'v': {
        options->v = 1;
        break;
      }
      case 'T': {
        options->t = 1;
        break;
      }
      default: {
        fprintf(stderr, "usage");
        exit(1);
      }
    }
  }
}