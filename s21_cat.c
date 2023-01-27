#include "s21_cat.h"

int main(int argc, char *argv[]) {
  void_stdin(argc);
  int err;
  key options = {0};
  parser(argc, argv, &options);
  if (options.b) options.n = 0;
  while (optind < argc) {
    if ((err = read_file(argv, &options)) == 1) {
      fprintf(stderr, "%s: %s: %s\n", argv[0], argv[optind], strerror(err));
    }
    optind++;
  }
  return 0;
}
