#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
	char *data = "{\"love\":[\"LOL\",\"Go shopping\"]}";
	cJSON * json = cJSON_Parse(data);

	char *json_data = NULL;
	printf("data:%s\n",json_data = cJSON_Print(json));

	free(json_data);
	cJSON_Delete(json);
	return 0;
}
