#ifndef C3_SIMPLEBASHUTILS_0_S21_CAT_H
#define C3_SIMPLEBASHUTILS_0_S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct keys {
  int b;  // нумерует только не пустые строки
  int e;  // все нечитаемые символы + сиволы конца строки как $
  int n;  // нумерует все строки
  int s;  // сжимает пустые смежные строки
  int t;  // отображает табы как "^I"
  int v;  // нечитаемые символы
} key;

void parser(int argc, char *argv[], key *options);
int read_file(char *argv[], key *options);
void void_stdin(int argc);

#endif  // C3_SIMPLEBASHUTILS_0_S21_CAT_H
