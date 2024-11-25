#include<stdio.h>
#define C "#include<stdio.h>%1$c#define C %2$c%3$s%2$c%1$c#define R return 0;%1$c#define M()int main(){FILE*f=fopen(%2$cGrace_kid.c%2$c,%2$cw%2$c);if(!f)return 1;fprintf(f,C,10,34,C);fclose(f);R}%1$cM()//a"
#define R return 0;
#define M()int main(){FILE*f=fopen("Grace_kid.c","w");if(!f)return 1;fprintf(f,C,10,34,C);fclose(f);R}
M()//a