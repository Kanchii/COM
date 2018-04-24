delim	[ \t]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?

%%
{ws}	{}
"+"	{return TADD;}
"-"	{return TSUB;}
"*"	{return TMUL;}
"/"	{return TDIV;}
"("	{return TAPAR;}
")"	{return TFPAR;}
\n	{return TFIM;}
"<" {return TMENOR;}
">" {return TMAIOR;}
">=" {return TMAIORIG;}
"<=" {return TMENORIG;}
"==" {return TIGUAL;}
"!=" {return TDIF;}
"&&" {return TAND;}
"||" {return TOR;}
"!" {return TNOT;}
{num}	{yylval=atof(yytext); return TNUM;}
