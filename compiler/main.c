#include "globals.h"
#include "util.h"

int lineno = 0;
FILE *source;
FILE *listing;
FILE *code;

int TraceScan = TRUE;

int main(int argc, char *argv[]) {
	char pgm[20];
	
	strcpy(pgm, argv[1]);
	if (strchr (pgm, '.') == NULL)
		strcat(pgm, ".tny");

	source = fopen(pgm, "r");
	if (source == NULL) {
		fprintf(stderr, "File %s not found\n", pgm);
		exit(1);
	}
	listing = stdout;
	TokenType t;
	while ((t = getToken()) != ENDFILE && t != ERROR);

	return 0;
}
