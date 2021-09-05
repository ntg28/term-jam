#include <stdio.h>
#include <curses.h>

#include "util.h"

const char *robot[][3] = {
    { // 0
	"Hello, you should be the new",
	"programming student.",
	"END"
    },
    { // 1
	"Here I'll teach you all about programming.",
	"END"
    },
    { // 2
	"So let's get started with the most simple code.",
	"END"
    },
    { // 3
	"THE FAMOUS: HELLO WORLD!",
	"END"
    },
    { // 4
	"I'll explain everything detailed for you, Ok?",
	"END"
    },
    { // 5
	"The first word `int` is a type.",
	"END"
    },
    { // 6
	"After we have `main()` this is our function name.",
	"END"
    },
    { // 7
	"And Bla, Bla, Bla...",
	"END"
    },
    { // 8
	"Now... I'll show you how AMAZING programming is.",
	"END"
    },
    { // 9
	"Are you ready?",
	"END"
    },
    { // 10
	"Dah, dah!",
	"END"
    },
    { // 11
	"Just a lot of words, Right?",
	"END"
    },
    { // 12
	"Les's compile it!",
	"END"
    },
    { // 13
	"Ahh... Error... Whaaat?",
	"END"
    },
    { // 14
	"Give me a second...",
	"END"
    },
    { // 15
	"Ok, let's go! Now you'll see the most",
	"AMAZING thing you ever saw in your life.",
	"END"
    },
    { // 16
	"...",
	"END"
    },
    { // 17
	"WTF, WHY THIS IS HAPPENING...",
	"END"
    },
    { // 18
	"AHH... calm down, breath...",
	"Let's see what's going on this code",
	"END"
    },
    { // 19
	"HERE! NOW I FIXED IT!",
	"END"
    },
    { // 20
	"Let's compile it again",
	"END"
    },
    { // 21
	"WHAT 173 ERRORS, HOW THIS IS POSSIBLE??",
	"END"
    },
    { // 22
	"calm down... calm down... don't get angry",
	"I can do it!",
	"END"
    },
    { // 23
	"I'll fix it, just give me a sec, ok...",
	"END"
    },
    { // 24
	"Let me see... Maybe here... Remove it...",
	"END"
    },
    { // 25
	"I think this will work now.",
	"END"
    },
    { // 26
	"Wait... move it to here... delete it.",
	"END"
    },
    { // 27
	"Ok, ok, I got it, now this should work.",
	"END"
    },
    { // 28
	"Let's compile it! Are you ready?",
	"END"
    },
    { // 29
	"You see... I GOT IT!",
	"END"
    },
    { // 30
	"Now I just need to run the executable.",
	"Let's do it!",
	"END"
    },
    { // 31
	"...",
	"END"
    },
    { // 32
	"AHHHHHHHHHHHHHHHHHHHHHHH",
	"AHHHHHHHHHHHHHHHHHHHH...",
	"END"
    },
};

const char *errors[][12] = {
    {"", "END"},
    {
	"awesome_stuff.c:185:4: error: syntax",
	"found 1 errors",
	"END"
    },
    {
	"awesome_stuff.c:355:32: error: undefined variable `togglebit`",
	"awesome_stuff.c:743:18: error: syntax error",
	"awesome_stuff.c:931:45: error: index out of range",
	"awesome_stuff.c:1028:45: error: trying access null pointer",
	"found 4 errors",
	"END"
    },
    {
	"awesome_stuff.c:1568:32: error: undefined variable `maria`",
	"awesome_stuff.c::4840: error: syntax error",
	"awesome_stuff.c:5830:45: error: index out of range",
	"awesome_stuff.c:6938:45: error: trying access null pointer",
	"unkown_library.c:134:32: error: struct has not field `url`",
	"unkown_library.c:394:18: error: undefined variable `cute_cat`",
	"bad_code_stuff.c:5018:45: error: `universes` cannot be indexed",
	"bad_code_stuff.c:5801:45: error: trying access null pointer",
	"...",
	"found 173 errors",
	"END"
    },
    {
	"successed compiled!",
	"END"
    },
    {
	"[1] 1900091 segmentation fault (core dumped) ./awesome_stuff",
	"END"
    }
};

const char *codes[][28] = {
    {"", "END"},
    {
	"int main() {",
	"	printf(\"Hello, World!\");",
	"}",
	"END"
    },
    {
	"#include \"awesome/url.c\"",
	"#include \"awesome/request.c\"",
	"#include \"awesome/hashmap.c\"",
	"#include \"awesome/vector.c\"",
	"#include \"awesome/unkown_library.c\"",
	"#include \"awesome/bad_code_stuff.c\"",
	"RESPONSE alias_for_do_request(URL url, HEADERS headers) {",
	"	return do_request(url, headers);",
	"}",
	"URL alias_for_random_url(char *query) {",
	"	return random_url(query);",
	"}",
	"CAT_GIF_FORMATED alias_for_format_cat_url_gif_to_CAT_GIF_FORMATED(RESPONSE resp) {",
	"	return format_cat_url_gif_to_CAT_GIF_FORMATED(resp.data);",
	"}",
	"RESPONSE do_something_awesome() {",
	"	URL url = alias_for_random_url(\"cute cat\");",
	"	return alies_for_do_request(url, DEFAULT_HEADERS);",
	"}",
	"RESPONSE get_random_cute_cat_gif_from_internet() {",
	"	return do_something_awesome();",
	"}",
	"CAT_GIF_FORMATED format_cute_cat_image(RESPONSE resp) {",
	"	RESPONSE awesome = get_random_cut_cat_gif_from_internet();",
	"	return alias_for_format_cat_url_gif_to_CAT_GIF_FORMATED(awesome);",
	"}",
	"END"
    }
};

void game_refresh(Game *game) {
    refresh();
    wnoutrefresh(game->code_win);
    wnoutrefresh(game->term_win);
    wnoutrefresh(game->robot_win);

    if (game->done == 1) {
        wnoutrefresh(game->thx_win);
    }

    doupdate();
}

void game_update(Game *game) {
    clear();
    werase(game->code_win);
    werase(game->term_win);
    werase(game->robot_win);

    if (game->done == 1) {
        werase(game->thx_win);
    }

    write_lines(game->code_win, 1, 2, codes[game->code_idx]);
    write_lines(game->term_win, 1, 2, errors[game->term_idx]);
    write_lines(game->robot_win, 1, 2, robot[game->robot_idx]);

    box(game->code_win, 58, 45);
    box(game->term_win, 58, 45);
    box(game->robot_win, 58, 45);

    if (game->done == 1) {
        mvwaddstr(game->thx_win, 2, 60 / 2 - 24 / 2, "ERROR: THANKS FOR PLAYING!");
        box(game->thx_win, 58, 45);
    }

    game_refresh(game);
}

void game_loop() {
    Game game = {0};
    int update_term[] = {13, 16, 21, 29, 31};

    game.code_win = newwin(LINES / 2 - 2, COLS - 4, 2, 2);
    game.term_win = newwin(LINES / 2 - 2, COLS - 4, LINES / 2, 2);
    game.robot_win = newwin(5, 60, 3, COLS - 64);
    game.thx_win = newwin(5, 60, LINES / 2 - 5 / 2, COLS / 2 - 60 / 2);

    while (1) {
	if (game.robot_idx == 3 || game.robot_idx == 10) {
	    game.code_idx++;
	}

	if (indexof(5, update_term, game.robot_idx) != -1) {
	    game.term_idx++;
	}

	if (game.robot_idx == sizeof(robot) / sizeof(*robot) - 1) {
	    game.done = 1;
	}

	game_update(&game);

	game.chr = getch();
	
	if (game.done == 1 || game.chr == 'q') {
	    break;
	}
	if (game.chr == 'j') {
	    game.robot_idx++;
	}
    }
}

int main() {
    curses_setup();
    game_loop();
    curses_close();
    return 0;
}
