#include "util.h"

int streq(const char *a, const char *b) {
    for (int i = 0; a[i] != '\0'; i++) {
	if (a[i] != b[i]) { return 0; }
    }
    return 1;
}

int indexof(int len, int *arr, int val) {
    for (int i = 0; i < len; i++) {
	if (arr[i] == val) { return i; }
    }
    return -1;
}

void curses_setup() {
    initscr();
    curs_set(0);
    cbreak();
    noecho();
}

void curses_close() {
    endwin();
}

void write_lines(WINDOW *win, int y, int x, const char **lines)
{
    for (int i = 0; streq(lines[i], "END") != 1; i++) {
	mvwaddstr(win, y + i, x, lines[i]);
    }
}
