#include "main.h"

void opening(dataStruct *data, char *argv[])
{
	if (data->operation_flag == OPEN_FILE) {
		static int i = 1;
		while (argv[i]) {
			if (argv[i][0] != '-')
				break;
			i++;
		}
		if (argv[i] == NULL) {
			data->operation_flag = NO_MORE_FILES_TO_READ;
			return;
		}
		data->fp = fopen(argv[i++], "r");
		if (data->fp == NULL) {
			fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
			data->error = 1;
		}
		data->operation_flag = READING_FROM_FILE;
	}
}
