#include "main.h"

void printing(dataStruct *data)
{
	if (data->operation_flag != READING_FROM_FILE
		&& data->operation_flag != OPEN_FILE)
		return;
	printf("%s", data->str_out);
}
