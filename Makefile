all:
	flex expr.l
	bison expr.y
	gcc expr.c expr.tab.c
