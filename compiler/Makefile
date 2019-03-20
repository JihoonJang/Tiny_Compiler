TARGET = 20161635

$(TARGET): main.o util.o lex.yy.o
	gcc -o $(TARGET) main.o util.o lex.yy.o
main.o: globals.h util.h main.c
	gcc -c -o main.o main.c
util.o: globals.h util.h util.c
	gcc -c -o util.o util.c
lex.yy.o: globals.h util.h lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c -ll
lex.yy.c: tiny.l
	lex tiny.l

clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f $(TARGET)
