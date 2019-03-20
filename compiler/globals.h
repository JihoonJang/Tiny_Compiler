#ifndef _GlOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef enum {
	ENDFILE, ERROR,
	IF, ELSE, INT, RETURN, VOID, WHILE,
	
	PLUS, MINUS, TIMES, OVER,
	LT, LTE, RT, RTE, EEQ, NEQ, EQ,
	SEMI, COMMA, LPAREN, RPAREN, LSQPAREN, RSQPAREN, LMPAREN, RMPAREN,

	NUM, ID
} TokenType;

extern FILE* source;
extern FILE* listing;
extern FILE* code;

extern int lineno;

extern int TraceScan;

#endif
