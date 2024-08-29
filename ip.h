#include "ip.c"
char **create_tab(int un,int deux);
void valid_IP(char **token,char *premier_octet,char *deuxieme_octet,char *troisieme_octet,char *quatrieme_octet,int *premier,int *deuxieme,int *troisieme,int *quatrieme,int count);
int generate_IP(char **bits,char **token,char *premier_octet,char *deuxieme_octet,char *troisieme_octet,char *quatrieme_octet);
