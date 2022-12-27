#include "main.h"  // проверяем, передан ли флаг

void processing(dataStruct *data)
{
	if (data->operation_flag != READING_FROM_FILE
		&& data->operation_flag != OPEN_FILE)
		return;
	if (data->flag_s == true)
		processing_s(data);
	if (data->flag_b == true)
		processing_b(data);
	if (data->flag_e == true)
		processing_e(data);
	if (data->flag_n == true)
		processing_n(data);
	if (data->flag_t == true)
		processing_t(data);
	if (data->flag_v == true)
		processing_v(data);
}
