#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LOGIN.h"
#define MAX_NAME 100
#define INPUT_FILE "login.txt"

int main()
{
	int count=0;
	int un=100;
	int deux=50;
    char nom[MAX_NAME];
    char prenom[MAX_NAME];
    char mdp[MAX_NAME];
	printf("Content-type: text/html\n\n");
	char **id=NULL;
	char **token=NULL;
    FILE *fr=NULL;
	printf("<!DOCTYPE html><html><head><title>login</title></head><body>");
    id=create_tab(un,deux);
    token=create_tab(un,deux);
    fr=open_fr();
    count=read_file(fr,token);
	generate_login(id,nom,prenom,mdp);//maka anle anarana vaovao
    compare(token,nom,prenom,mdp,count);
    printf("</body></html>");
    for(int i=0;i<un;i++)
	{
		free(id[i]);
	}
	for(int i=0;i<un;i++)
	{
		free(token[i]);
	}
	free(id);
	free(token);
	fclose(fr);
	
	return 0;
}






