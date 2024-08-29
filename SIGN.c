#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_FILE "login.txt"
FILE *open_file() //manokatra anle student.txt
{
	FILE *fw=NULL;
	fw=fopen(INPUT_FILE,"a");
	if(fw==NULL)
	{
		printf("the file %s can't open",INPUT_FILE);
		exit(1);
	}
	return fw;
}
char **create_tab(int un,int deux)
{
	int i=0;
	char **name=NULL;
	name=(char**)malloc(un*sizeof(char*));
	for(i=0;i<un;i++)
	{
		name[i]=(char*)malloc(deux*sizeof(char));
	}
	if(name == NULL)
	{
		printf("Erreur d'allocation");
		exit(1);
	}
	return name;
}
void generate_sign(char **id,char *nom,char *prenom,char *mdp,char *rmdp) //maka anle anarana vaovao
{
	char *get=getenv("QUERY_STRING");
    int i=0;
    int k=0;
    char *token;
    token = strtok(get, "&=");
    while (token != NULL)
    {
       strcpy(id[i],token); //nom=nax&prenom=narindra&genre=M
       for(k=0;k<strlen(id[i]);k++)
       {
		   size_t k = strcspn(id[i], "+");
		   if (k < strlen(id[i]))
		   {
			  id[i][k] = ' ';
		   }
       }
        token = strtok(NULL,"&=");
        i++;
	 }
	strcpy(nom,id[1]);
	strcpy(prenom,id[3]);
	strcpy(mdp,id[5]);
	strcpy(rmdp,id[7]);
}
void compare(FILE *fw,char *nom,char *prenom,char *mdp,char *rmdp)
{
	
	
		if(strcmp(mdp,rmdp)==0)
		{
			fprintf(fw,"%s;%s;%s\n",nom,prenom,mdp);//miaraka amle mod mod mod 
			printf("<h1>%s %s's creation compte with succed </h1>",nom,prenom);
			printf("<p>cliquez ici si vous voulez se connecter a un compte<a href='login.html'>login</a></p>");	
		}
		else
	    {
		printf("echec sur la confirmation du mdp<br>");
		printf("<a href='login.html'>click here to try again</a>");
	    }
}
