#include "LOGIN.c"
FILE *open_fr();
int read_file(FILE *fr,char **token);
char **create_tab(int un,int deux);
void generate_login(char **id,char *nom,char *prenom,char *mdp); //maka anle anarana vaovao
void compare(char **token,char *nom,char *prenom,char *mdp,int count); //maka anle anarana vaovao
