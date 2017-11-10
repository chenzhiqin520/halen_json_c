#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
	char *string = "{\"family\":[\"father\",\"mother\",\"brother\",\"sister\",\"somebody\"]}";
	cJSON *json = cJSON_Parse(string);
	cJSON *node = NULL;
	node = cJSON_GetObjectItem(json,"family");
	if(node == NULL)
	{
		printf("family node == NULL\n");
	}
	else
	{
		printf("found family node\n");
	}
	node =cJSON_GetObjectItem(json,"famil");
	if(node == NULL)
	{
		printf("famil node == NULL\n");
	}
	else
	{
		printf("found famil node\n");
	}
	if(1 == cJSON_HasObjectItem(json,"family"))
	{
		printf("found family node\n");
	}
	else
	{
		printf("node found family node\n");
	}
	if(1 == cJSON_HasObjectItem(json,"famil"))
	{
		printf("found famil node\n");
	}
	else
	{
		printf("not found famil node\n");
	}

	node = cJSON_GetObjectItem(json,"family");
	if(node->type == cJSON_Array)
	{
		printf("array size is %d",cJSON_GetArraySize(node));
	}
	cJSON *tnode = NULL;
	int size = cJSON_GetArraySize(node);
	int i;
	for(i=0;i<size;i++)
	{
		tnode = cJSON_GetArrayItem(node,i);
		if(tnode->type == cJSON_String)
		{
			printf("value[%d]:%s\n",i,tnode->valuestring);
		}
		else
		{
			printf("node type is not stirng\n");
		}
	}

	cJSON_ArrayForEach(tnode,node)
	{
		if(tnode->type == cJSON_String)
		{
			printf("int forEach: vale:%s\n",tnode->valuestring);
		}
		else
		{
			printf("node's type is not string\n");
		}
	}
	return 0;
}
