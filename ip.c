#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100
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
int generate_IP(char **bits,char **token,char *premier_octet,char *deuxieme_octet,char *troisieme_octet,char *quatrieme_octet)
{
	char *get=getenv("QUERY_STRING");
    char *ken;
    int b=0;
    ken = strtok(get, "=");
    while (ken != NULL)
    {
       strcpy(bits[b],ken); 
       ken = strtok(NULL,"=");
       b++;
	}
	char ip[MAX_NAME];
	strcpy(ip,bits[1]); 
	ip[strcspn(ip, "\n")] = '\0';
	char *tok;
	tok = strtok(ip,".");
	int i=0;
	while (tok != NULL)
	{
		strcpy(token[i],tok);
		tok = strtok(NULL,".");
		i++;
	}
	int ok=0;
	char *endptr=NULL;
	int base=10;
	long opt_enum=0;
	for(int c=0;c<i;c++)
	{
		opt_enum=strtol(token[c], &endptr, base); //strtol detecte les caractere non base 10
		if(opt_enum<0 || opt_enum>255 )
		{
          printf("IP non valide");
          exit(1);
		}
		if (endptr == token[c] || *endptr != '\0') //egal quand le premier caractere trouver n'est pas un chiffre
		{
          printf("IP non valide");
                exit(1);
	            
		}
		if(*endptr == '\0' && opt_enum>-1 && opt_enum<256) // Si tout est bon, afficher le nombre converti et sortir de la boucle
        {
			ok++;
	    }
	}
    if(ok==4)
    {
		strcpy(premier_octet,token[0]);
		strcpy(deuxieme_octet,token[1]);
		strcpy(troisieme_octet,token[2]);
		strcpy(quatrieme_octet,token[3]);
	}
	return i;
}
void valid_IP(char **token,char *premier_octet,char *deuxieme_octet,char *troisieme_octet,char *quatrieme_octet,int *premier,int *deuxieme,int *troisieme,int *quatrieme,int count)
{
	
	if(count!=4)
	{
          printf("IP non valide");
            exit(1);
	}
	 
		
	if(count==4)
	{
		*premier=atoi(premier_octet);
		
		
		
		*deuxieme=atoi(deuxieme_octet);
		
		
		
		*troisieme=atoi(troisieme_octet);
		
		
		
		*quatrieme=atoi(quatrieme_octet);
		
		if(*premier<128)
		{
			printf("IP de classe A");
		}
		if(*premier>127 && *premier<192 )
		{
			printf("IP de classe B");
		}
		if(*premier>191 && *premier<224)
		{
			printf("IP de classe C");
		}
		if(*premier>223 && *premier<240)
		{
			printf("IP de classe D");
		}
		if(*premier>239 && *premier<256)
		{
			printf("IP de classe E");
		}
	}
}


