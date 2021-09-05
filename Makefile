CC = gcc
FILES = util.c
NCURSES = $(shell pkg-config ncurses --libs --cflags)

main: main.c $(FILES)
	$(CC) -o $@ $< $(FILES) $(NCURSES)
