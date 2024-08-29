#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip.h"
#define MAX_NAME 100

int main()
{
	printf("Content-type: text/html\n\n");
	printf("<!DOCTYPE html><html><head><title>IP</title></head><body>");
	int count=0;
	int pd=100;
	int dd=50;
	char premier_octet[MAX_NAME];
    char deuxieme_octet[MAX_NAME];
    char troisieme_octet[MAX_NAME];
    char quatrieme_octet[MAX_NAME];
    int premier=0;
    int deuxieme=0;
    int troisieme=0;
    int quatrieme=0;
	char **token=NULL;
	char **bits=NULL;
	token=create_tab(pd,dd);
	bits=create_tab(pd,dd);
	count=generate_IP(bits,token,premier_octet,deuxieme_octet,troisieme_octet,quatrieme_octet);
	valid_IP(token,premier_octet,deuxieme_octet,troisieme_octet,quatrieme_octet,&premier,&deuxieme,&troisieme,&quatrieme,count);
	printf("</body></html>");
	for(int i=0;i<pd;i++)
	{
		free(token[i]);
	}
	free(token);
	for(int i=0;i<pd;i++)
	{
		free(bits[i]);
	}
	free(bits);
	return 0;
}





