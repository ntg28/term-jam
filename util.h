#ifndef __UTIL__
#define __UTIL__

#include <curses.h>

typedef struct Game {
    char chr;

    WINDOW *code_win;
    WINDOW *term_win;
    WINDOW *robot_win;
    WINDOW *thx_win;

    int code_idx;
    int term_idx;
    int robot_idx;

    int done;
} Game;

int streq(const char *a, const char *b);
int indexof(int len, int *arr, int val);

void curses_setup();
void curses_close();

void write_lines(WINDOW *win, int y, int x, const char **lines);

#endif
