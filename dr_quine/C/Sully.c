#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CODE "#include<stdio.h>%1$c#include<stdlib.h>%1$c#include<string.h>%1$c#define CODE %2$c%3$s%2$c%1$cint main(void){int i=%4$d;if(i<=0)return 0;char c[100];sprintf(c,%2$cSully_%%d.c%2$c,i);if(!strcmp(c,__FILE__))i--;char n[100];sprintf(n,%2$cSully_%%d.c%2$c,i);char e[100];sprintf(e,%2$cSully_%%d%2$c,i);FILE*f=fopen(n,%2$cw%2$c);if(f==NULL)return 1;fprintf(f,CODE,10,34,CODE,i);fclose(f);char o[300];sprintf(o,%2$cgcc -o %%s %%s%2$c,e,n);system(o);char r[200];sprintf(r,%2$c./%%s%2$c,e);system(r);return 0;}%1$c"
int main(void){int i=5;if(i<0)return 0;char c[100];sprintf(c,"Sully_%d.c",i);if(!strcmp(c,__FILE__))i--;char n[100];sprintf(n,"Sully_%d.c",i);char e[100];sprintf(e,"Sully_%d",i);FILE*f=fopen(n,"w");if(f==NULL)return 1;fprintf(f,CODE,10,34,CODE,i);fclose(f);char o[300];sprintf(o,"gcc -o %s %s",e,n);system(o);char r[200];sprintf(r,"./%s",e);system(r);return 0;}
