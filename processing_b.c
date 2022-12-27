#include "main.h"

void processing_b(dataStruct *data)
{
	char str_in[262144] = {0};
	for (int i = 0; data->str_out[i]; i++)
	    str_in[i] = data->str_out[i];

	int i = 0;
	int j = 0;
	static int str_count = 1;
	static bool flag_b = 1;
	while (str_in[i] != '\0') {
		if (flag_b == 1 && str_in[i] != '\n') {
			sprintf(&data->str_out[j], "%6d ", str_count++);
			flag_b = 0;
			j += 7;
		}
		if (str_in[i] == '\n')
			flag_b = 1;
		data->str_out[j++] = str_in[i++];
	}
    data->str_out[j] = '\0';
}
