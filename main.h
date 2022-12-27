#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>   // printf fopen fread
# include <stdbool.h> // false and true
# include <stdlib.h>  // exit
# include <string.h>  // strcmp
# include <unistd.h>  // read

# define NO_MORE_FILES_TO_READ 0
# define OPEN_FILE 3
# define READING_FROM_FILE 5

typedef struct flagsAndText
{
    bool flag_b;            // - нумерует только непустые строки
    bool flag_e;            // - предоплагает и -v , отображает символы конца строки как $

    bool flag_n;            // - нумерует все выходные строки
    bool flag_s;            // - сжимает несколько смежных строк
    bool flag_t;            // - отображает табы как ^I
    bool flag_v;            // - отображает все нечитаемые символы

  FILE *fp;
  int operation_flag;
  char str_out[262144];   // необходимо 16*8=128КБ , с двойным запасом. 256 КБ.
  int error;
} dataStruct;




void getFromStdin(int argc);
void parsingShortFlags(dataStruct *data, char *argv[]);
void parsingLongFlags(dataStruct *data, char *argv[]);
void opening(dataStruct *data, char *argv[]);
void reading(dataStruct *data);
void printing(dataStruct *data);
void processing(dataStruct *data);
void processing_t(dataStruct *data);
void processing_n(dataStruct *data);
void processing_e(dataStruct *data);
void processing_b(dataStruct *data);
void processing_s(dataStruct *data);
void processing_v(dataStruct *data);


#endif //MAIN_H

