#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SIGN.h"
#define MAX_NAME 100
int main()
{
	
	int un=100;
	int deux=50;
    char nom[MAX_NAME];
    char prenom[MAX_NAME];
    char mdp[MAX_NAME];
    char rmdp[MAX_NAME];
    char **id=NULL;
	printf("Content-type: text/html\n\n");
    FILE *fw=NULL;
	printf("<!DOCTYPE html><html><head><title>modify</title></head><body>");
    id=create_tab(un,deux);
    fw=open_file();
    generate_sign(id,nom,prenom,mdp,rmdp);
    compare(fw,nom,prenom,mdp,rmdp);
    printf("</body></html>");
    for(int i=0;i<un;i++)
	{
		free(id[i]);
	}
	free(id);
	fclose(fw);
	return 0;
}






