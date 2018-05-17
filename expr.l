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
"int" {yylval.tipo = TIPO_INT; return TINT;}
"String" {return TSTRING;}
"float" {yylval.tipo = TIPO_FLOAT; return TFLOAT;}
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
{literal} {return TLITERAL;}
{num}	{return TNUM;}
{id}  {strncpy(yylval.id, yytext, 10); posicao++; return TID;}
. {printf("Erro léxico na linha %d\n", linha); exit(0);}
