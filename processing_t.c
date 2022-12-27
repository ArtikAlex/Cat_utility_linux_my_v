#include "main.h"

void processing_t(dataStruct *data)
{
	char str_in[262144] = {0};
	for (int i = 0; data->str_out[i]; i++)
		str_in[i] = data->str_out[i];
    int j = 0;
	for(int i = 0; str_in[i]; i++)
	{
		if (str_in[i] == '\t') {
			data->str_out[j++] = '^';
			data->str_out[j++] = 'I';
			continue;
		}
		data->str_out[j++] = str_in[i];
	}
    data->str_out[j] = '\0';
}
