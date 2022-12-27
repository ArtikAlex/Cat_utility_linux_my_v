#include "main.h"

void reading(dataStruct *data)
{
	if (data->operation_flag == READING_FROM_FILE) {
		size_t read_size = fread(data->str_out, 1, 5, data->fp); // тут было 16384
		data->str_out[read_size] = '\0';
		if (ferror (data->fp))
		{
			fprintf (stderr, "Ошибка чтения из файла.\n");
			data->error = 1;
			data->operation_flag = NO_MORE_FILES_TO_READ;
		}
		if (read_size != 5)
			data->operation_flag = OPEN_FILE;
	}
}
