#include<stdio.h>/*a*/
char*f(){return "#include<stdio.h>//a%1$cchar*f(){return %2$c%3$s%2$c;}int main(){return printf(f(),10,34,f());/*b*/}";}int main(){return printf(f(),10,34,f());/*b*/}