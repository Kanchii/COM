all:
	flex expr.l
	bison expr.y
	gcc expr.c expr.tab.c

clean:
	rm expr.tab.c lex.yy.c

.PHONY: clean all
