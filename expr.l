delim	[ \t]
ws	{delim}+
letra [A-Za-z]
digito	[0-9]
id  (_|{letra})+(_|{letra}|{digito})*
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
literal (\".*\")

%%
{ws}	{}
"+"	{return TADD;}
"-"	{return TSUB;}
"*"	{return TMUL;}
"/"	{return TDIV;}
"("	{return TAPAR;}
")"	{return TFPAR;}
"{" {return TACH;}
"}" {return TFCH;}
";" {return TPEV;}
"," {return TVIR;}
"\n" {linha++;}
"if" {return TIF;}
"else" {return TELSE;}
"print" {return TPRINT;}
"read" {return TREAD;}
"while" {return TWHILE;}
"void" {return TVOID;}
"int" {return TINT;}
"String" {return TSTRING;}
"float" {return TFLOAT;}
"return" {return TRETURN;}
">=" {return TMAIORIG;}
"<=" {return TMENORIG;}
"<" {return TMENOR;}
">" {return TMAIOR;}
"==" {return TIGUAL;}
"=" {return TATRIB;}
"!=" {return TDIF;}
"&&" {return TAND;}
"||" {return TOR;}
"!" {return TNOT;}
{literal} {yylval.tipo = TIPO_STRING; yylval.value.stringV = (char *)malloc(sizeof(char) * strlen(yytext)); strcpy(yylval.value.stringV, yytext); return TLITERAL;}
{num}	{if(ehFloat(yytext)){yylval.tipo = TIPO_FLOAT; yylval.value.floatV = atof(yytext);} else {yylval.tipo = TIPO_INT; yylval.value.intV = atoi(yytext);}; return TNUM;}
{id}  {yylval.tipo = TIPO_ID; strncpy(yylval.value.id, yytext, 10); return TID;}
. {printf("Erro léxico na linha %d\n", linha); exit(0);}
