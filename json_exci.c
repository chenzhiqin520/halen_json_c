#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main(void)
{
	char *char_json = "{\"habit\":\"lol\"}";
	cJSON *json = cJSON_Parse(char_json);

	char *buf = NULL;
	printf("data:%s\n",buf = cJSON_Print(json));
	
	FILE *fp =fopen("exec.json","w");
	fwrite(buf,strlen(buf),1,fp);

	fclose(fp);
	free(buf);
	cJSON_Delete(json);
	return 0;
}
