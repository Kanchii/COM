FIG_OUT = svg

all:
	flex expr.l
	bison expr.y
	gcc expr.c expr.tab.c funcoes.c

fig:
	dot -T$(FIG_OUT) graph.dot -o graph.$(FIG_OUT)
	eog graph.$(FIG_OUT)

jasmin:
	./a.out $(i)
	java -jar jasmin.jar JVM.j
	java JVM

.PHONY: all fig
