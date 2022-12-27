#include "main.h"

void processing_v(dataStruct *data)
{
    char str_in[262144] = {0};
    for (int i = 0; data->str_out[i]; i++)
        str_in[i] = data->str_out[i];

    for (int i = 0, j = 0; str_in[i] != '\0'; i++) {
        if ((str_in[i] >= 0 && str_in[i] <= 8) || (str_in[i] >= 10 && str_in[i] <= 31)) {
            data->str_out[j++] = '^';
            data->str_out[j++] = str_in[i] + 64;
        } else if (str_in[i] == 127) {
            data->str_out[j++] = '^';
            data->str_out[j++] = str_in[i] - 64;
        } else {
            data->str_out[j] = str_in[i];
            j++;
        }
    }
    return;
}
