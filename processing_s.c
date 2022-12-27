#include "main.h"

void processing_s(dataStruct *data)
{
    int j = 0;
    for (int i = 0; data->str_out[i]; i++, j++) {
        static bool first = true;
        data->str_out[j] = data->str_out[i];
        if (data->str_out[i] == '\n' && first == false) {
            first = true;
            continue;
        }
        if (data->str_out[i] == '\n') {
            while (data->str_out[i] == '\n')
                i++;
            i--;
        }
        first = false;
    }
    data->str_out[j] = '\0';
}
