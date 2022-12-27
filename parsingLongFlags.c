#include "main.h"

static void pars(dataStruct *data, char *str);

void parsingLongFlags(dataStruct *data, char *argv[])
{
	for (int i = 1; argv[i]; i++) {
		if (argv[i][0] == '-' && argv[i][1] == '-')
			pars(data, argv[i]);
	}
}

static void pars(dataStruct *data, char *str)
{
	if (strcmp(str, "--number-nonblank") == 0)
		data->flag_b = true;
	else if (strcmp(str, "--number") == 0)
		data->flag_n = true;
	else if (strcmp(str, "--squeeze-blank") == 0)
		data->flag_s = true;
	else
	{
		printf("cat: unrecognized option \'%s\'\n", str);
		data->error = 1;
	}
}
