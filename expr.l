delim	[ \t]
ws	{delim}+
letra [A-Za-z]
digito	[0-9]
id  (_|{letra})+(_|{letra}|{digito})*
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
literal \".*\"

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
\n	{return TFIM;}
"if" {return TIF;}
"else" {return TELSE;}
"print" {return TPRINT;}
"read" {return TREAD;}
"while" {return TWHILE;}
"void" {return TVOID;}
"int" {return TINT;}
"string" {return TSTRING;}
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
{literal} {return TLITERAL;}
{num}	{yylval=atof(yytext); return TNUM;}
{id}  {return TID;}
