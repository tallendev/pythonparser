CCC = clang++
LEX = flex
YACC = bison
CFLAGS = -g -Wall -std=c++11
LEXFLAGS = -Wno-unused

#LEXDEBUG = -d
YACCDEBUG = -Wconflicts-sr -vtd

OBJS = main.o lex.yy.o parse.tab.o ast.o symboltable.o 

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp parse.y scan.l parse.tab.c lex.yy.c
	$(CCC) $(CFLAGS) -c main.cpp

parse.tab.c: parse.y
	$(YACC)  $(YACCDEBUG) parse.y
	#$(YACC) --graph $(YACCDEBUG) parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c parse.tab.c

lex.yy.c: scan.l parse.tab.o
	$(LEX) $(LEXDEBUG) scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

%.o : %.cpp
	echo $<
	$(CCC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h
	rm -f parse.output
	rm -f *.gv
	rm -f *.png
	rm -f *.pdf
	rm -f *.ps
