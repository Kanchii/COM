#include <stdio.h>

extern FILE *yyin;

int main()
{
	yyin = stdin;
	printf("Digite uma expressao:\n> ");
	yyparse();
	return 0;
}
