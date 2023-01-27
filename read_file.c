#include "s21_cat.h"

int read_file(char *argv[], key *options) {
  int err = 0;
  FILE *fl = fopen(argv[optind], "r");
  if (fl != 0) {
    char cur;
    char last, prelast = '\n';
    int str_count = 0;
    int counter = 0;  // count symbols
    while ((cur = fgetc(fl)) != EOF) {
      if (options->s) {
        if (cur == '\n' && prelast == '\n' && last == '\n') {
          continue;
        }
      }
      if (options->b) {
        if (cur != '\n') {
          if (counter == 0) {
            printf("%6d\t", ++str_count);
            counter = 1;
          }
        } else {
          counter = 0;
        }
      }
      if (options->n) {
        if (counter == 0) {
          printf("%6d\t", ++str_count);
          counter = 1;
        }
        if (cur == '\n') {
          counter = 0;
        }
      }
      if (options->e) {
        if (cur == '\n') printf("$");
      }
      if (options->t) {
        if (cur == '\t') {
          printf("^I");
          continue;
        }
      }
      if (options->v) {
        if (cur < 32 && cur != '\n' && cur != '\t') {
          printf("^%c", cur + 64);
          continue;
        } else if (cur == 127) {
          printf("^?");
          continue;
        }
      }
      printf("%c", cur);
      last = prelast;
      prelast = cur;
    }
  } else {
    err = 1;
  }
  fclose(fl);
  return err;
}
