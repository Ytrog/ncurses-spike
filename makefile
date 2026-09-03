nspike: nspike.c
	cc $^ -o $@ -lncurses
run: nspike
	./$<
.PHONY: run
