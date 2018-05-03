#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;

int main(int argc, char *argv[])
{
	int tam = strlen(argv[1]);
	char *path = (char *)malloc(sizeof(char) * (tam + 1));
	strcpy(path, argv[1]);
	yyin = fopen(path, "r");
	//printf("Digite uma expressao:\n> ");
	yyparse();
	return 0;
}
