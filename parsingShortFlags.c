#include "main.h"

static void pars(dataStruct *data, char *str);
static void rulesForFlag_b(dataStruct *data);
static void rulesForFlag_n(dataStruct *data);
static void rulesForFlag_e(dataStruct *data);
static void rulesForFlag_t(dataStruct *data);

void parsingShortFlags(dataStruct *data, char *argv[])
{
	for (int i = 1; argv[i]; i++) {    // i не ноль, потому, что 0 указывает на название.
		if (argv[i][0] == '-' && argv[i][1] != '-')
			pars(data, argv[i]);
	}
}

static void pars(dataStruct *data, char *str)
{
	for (int i = 1; str[i]; i++) {
		if (str[i] == 'b')
			rulesForFlag_b(data);
		else if (str[i] == 'e')
			rulesForFlag_e(data);
		else if (str[i] == 'E')
			data->flag_e = true;
		else if (str[i] == 'n')
			rulesForFlag_n(data);
		else if (str[i] == 's')
			data->flag_s = true;
		else if (str[i] == 't')
			rulesForFlag_t(data);
		else if (str[i] == 'T')
			data->flag_t = true;
		else
		{
			printf("cat: invalid option -- \'%c\'\n", str[i]);
			data->error = 1;
		}

	}
}

/* флаг -b в приоритете, по сравнению с -n */
static void rulesForFlag_b(dataStruct *data) {
	data->flag_b = true;
	data->flag_n = false;
}

/* флаг -b в приоритете, по сравнению с -n */
static void rulesForFlag_n(dataStruct *data) {
	if (data->flag_b != true)
		data->flag_n = true;
}

//флаг -e дополнительно включает флаг -v
static void rulesForFlag_e(dataStruct *data) {
	data->flag_e = true;
	data->flag_v = true;
}

//флаг -t дополнительно включает флаг -v
static void rulesForFlag_t(dataStruct *data) {
	data->flag_t = true;
	data->flag_v = true;
}
