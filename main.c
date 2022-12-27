#include "main.h"

int main(int argc, char *argv[]) {
	dataStruct data = {0, .operation_flag = OPEN_FILE};

	getFromStdin(argc);
	parsingShortFlags(&data, argv);
	parsingLongFlags(&data, argv);

	while (data.operation_flag) {
		opening(&data, argv);
		reading(&data);
		processing(&data);
		printing(&data);
	}
	return data.error;
}
