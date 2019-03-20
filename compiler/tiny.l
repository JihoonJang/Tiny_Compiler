%{
#include "globals.h"
#include "util.h"

#define MAXTOKENLEN 40
char tokenString[MAXTOKENLEN + 1];
int yywrap(void) {return 1;}
%}

digit		[0-9]
number		{digit}+
letter		[a-zA-Z]
identifier	{letter}+
newline		\n
whitespace	[ \t]+

%%

"if"		{return IF;}
"else"		{return ELSE;}
"int"		{return INT;}
"return"	{return RETURN;}
"void"		{return VOID;}
"while"		{return WHILE;}

"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return TIMES;}
"/"		{return OVER;}
"<"		{return LT;}
"<="		{return LTE;}
">"		{return RT;}
">="		{return RTE;}
"=="		{return EEQ;}
"!="		{return NEQ;}
"="		{return EQ;}
";"		{return SEMI;}
","		{return COMMA;}
"("		{return LPAREN;}
")"		{return RPAREN;}
"["		{return LSQPAREN;}
"]"		{return RSQPAREN;}
"{"		{return LMPAREN;}
"}"		{return RMPAREN;}
"/*"		{	char c;
			int done = FALSE;
			int error = FALSE;
			do {
				while ((c = input()) != '*') {
					if (c == '/')
						error = TRUE;
					else if (c == EOF)
						return ERROR;
					else {
						error = FALSE;
						if (c == '\n')
							lineno++;
					}
				}
				if (error)
					return ERROR;
				while ((c = input()) == '*');
				if (c == '/')
					done = TRUE;
			} while (!done);
		}
"*/"		{return ERROR;}
<<EOF>>		{return ENDFILE;}

{whitespace}	{/* Do Nothing */}
{number}	{return NUM;}
{identifier}	{return ID;}
{newline}	{lineno++;}

%%

TokenType getToken(void) {
	static int firstTime = TRUE;
	TokenType currentToken;
	if (firstTime) {
		fprintf(listing, "   line number             token          lexeme\n");
		fprintf(listing, "----------------------------------------------------\n");
		firstTime = FALSE;
		lineno++;
		yyin = source;
		yyout = listing;
	}
	currentToken = yylex();
	strncpy(tokenString, yytext, MAXTOKENLEN);
	if (TraceScan) {
		printToken(currentToken, tokenString);
	}
	return currentToken;
}
