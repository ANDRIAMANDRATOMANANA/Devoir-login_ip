#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME 100
#define INPUT_FILE "login.txt"
FILE *open_fr() 
{
	FILE *fr=NULL;
	fr=fopen(INPUT_FILE,"r");
	if(fr==NULL)
	{
		printf("the file %s can't open",INPUT_FILE);
		exit(1);
	}
	return fr;
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
int read_file(FILE *fr,char **token) //mamaky login.txt
{
	char chaine[500];
	int i=0;
	while(fgets(chaine,500,fr)!=NULL)
	{
		chaine[strcspn(chaine, "\n")] = '\0';
		char *tok;
		tok = strtok(chaine,";");
		while (tok != NULL)
		{
			strcpy(token[i],tok); //nom=nax&prenom=narindra&genre=M
			tok = strtok(NULL,";");
			i++;
		}
	}
	return i;
}
void generate_login(char **id,char *nom,char *prenom,char *mdp) //maka anle anarana vaovao
{
	char *get=getenv("QUERY_STRING");//gestion de login
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
	
	for (int a=0;a<strlen(nom);a++)
	{
			
			nom[a]=toupper(nom[a]); //on change  en majuscule le nom pour etre comparable
	}
	for (int a=0;a<strlen(prenom);a++)
	{
			
			prenom[a]=toupper(prenom[a]); //on change  en majuscule le prenom pour etre comparable
	}
	for (int a=0;a<strlen(mdp);a++)
	{
			
	    	mdp[a]=toupper(mdp[a]); //on change  en majuscule le genre pour etre comparable
	}
}
void compare(char **token,char *nom,char *prenom,char *mdp,int count) 
{
	for(int k=0;k<count;k++)
	{
		for (int a=0;a<strlen(token[k]);a++)
		{
			token[k][a]=toupper(token[k][a]); //on change  en majuscule les id pour etre comparable
	    }
	}
	int ok=0;
	int i=0;
	for(i=0;i<count;i++)
	{
		if(strcmp(token[i],nom)==0 && strcmp(token[i+1],prenom)==0 && strcmp(token[i+2],mdp)==0)
		{
			ok++;
			printf("<h1>successful connexion of %s %s</h1>",token[i],token[i+1]);
			

			printf("<h1>IP</h1>\n\
			<form action='ip.cgi' method='get'>\n\
				 enter your adress IP:<br>\n\
				 <input required  type='text' name='ip'/><br>\n\
				<input type='submit' value='envoyer'>\n\
			</form>");
		}
		i=i+2;
	}
	if(ok==0)
	{
		printf("connexion failure<br>");
		printf("<a href='login.html'>click here to try again</a>");
	}
	
}


