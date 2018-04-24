#include <stdio.h>

extern FILE *yyin;

int main()
{
	yyin = fopen("t", "r");
	//printf("Digite uma expressao:\n> ");
	yyparse();
	return 0;
}
