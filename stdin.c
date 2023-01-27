#include "s21_cat.h"

void void_stdin(int argc) {
  char buf[4096];

  if (argc == 1) {
    fscanf(stdin, "%s", buf);
    while (21) {
      printf("%s\n", buf);
      fscanf(stdin, "%s", buf);
    }
  } else {
    return;
  }
}
