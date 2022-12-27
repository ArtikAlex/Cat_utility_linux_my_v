#include "main.h"
# define BUF_SIZE 4096

void getFromStdin(int argc) {
	char buf[BUF_SIZE];

	if (argc != 1)
		return;
	fscanf(stdin, "%s", buf);
	while (21) {
		printf("%s\n", buf);
		fscanf(stdin, "%s", buf);
	}
	exit(EXIT_SUCCESS);
}
