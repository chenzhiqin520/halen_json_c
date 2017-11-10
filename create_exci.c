#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
	cJSON *json = cJSON_CreateObject();
	cJSON_AddStringToObject(json,"country","china");

	cJSON *array = NULL;
	cJSON_AddItemToObject(json,"stars",array=cJSON_CreateArray());
	cJSON *obj = NULL;
	cJSON_AddItemToArray(array,obj=cJSON_CreateObject());
	cJSON_AddItemToObject(obj,"name",cJSON_CreateString("Faye"));
	cJSON_AddStringToObject(obj,"address","beijing");

	cJSON_AddItemToArray(array,obj=cJSON_CreateObject());
	cJSON_AddItemToObject(obj,"name",cJSON_CreateString("andy"));
	cJSON_AddItemToObject(obj,"address",cJSON_CreateString("HK"));

	cJSON_AddItemToArray(array,obj=cJSON_CreateObject());
	cJSON_AddStringToObject(obj,"name","eddie");
	cJSON_AddStringToObject(obj,"address","TaiWan");

	FILE *fp = fopen("create.json","w");
	char *buf = cJSON_Print(json);
	fwrite(buf,strlen(buf),1,fp);
	fclose(fp);
	cJSON_Delete(json);

	return 0;
}
