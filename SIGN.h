#include "SIGN.c"
FILE *open_file();
int read_file(FILE *fr,char **token);
char **create_tab(int un,int deux);
void generate_sign(char **id,char *nom,char *prenom,char *mdp,char *rmdp);
void compare(FILE *fw,char *nom,char *prenom,char *mdp,char *rmdp);
