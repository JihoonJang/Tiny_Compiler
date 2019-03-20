#include "globals.h"
#include "util.h"

void printToken( TokenType token, const char* tokenString ) {
	char tokenKind[11];
	int i;
	switch (token) {
	case IF:
	case ELSE:	
	case INT:
	case RETURN:
	case VOID:
	case WHILE:
		strcpy(tokenKind, tokenString);
		i = 0;
		while (tokenKind[i] != '\0')
			tokenKind[i++] += 'A' - 'a';
        	break;

	case PLUS:
	case MINUS:
	case TIMES:
	case OVER:
	case LT:
	case LTE:
	case RT:
	case RTE:
	case EEQ:
	case NEQ:
	case EQ:
	case SEMI:
	case COMMA:
	case LPAREN:
	case RPAREN:
	case LSQPAREN:
	case RSQPAREN:
	case LMPAREN:
	case RMPAREN:
		strcpy(tokenKind, tokenString);
		break;

	case NUM:
		strcpy(tokenKind, "NUM");
		break;
	case ID:
		strcpy(tokenKind, "ID");
		break;
	case ENDFILE:
		strcpy(tokenKind, "EOF");
		break;
	case ERROR:
		strcpy(tokenKind, "ERROR");
		break;
	}
        fprintf(listing, "\t%d", lineno);
        fprintf(listing, "\t\t%s", tokenKind);
        fprintf(listing, "\t\t   %s\n", tokenString);

}
