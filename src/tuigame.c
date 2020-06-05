#include "tuigame.h"

long long TimeGetElapsed(struct timeval t0, struct timeval t1) {
    return (t1.tv_sec - t0.tv_sec) * 1e6 + (t1.tv_usec - t0.tv_usec);
}

void NcursesInit(void) {
    initscr();             /* start curses mode */
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    curs_set(FALSE);       /* no cursor shown */
    nodelay(stdscr, TRUE); /* getch be non-blocking */
    cbreak();              /* get chars immediately */
    noecho();              /* do not echo chars */
    /* print title and game area border */
    mvaddstr(0, 0, BANNER_STRING);
    mvhline(CEILING, 0, '_', COLS);
    mvhline(BOTTOM, 0, '"', COLS);
    mvvline(TOP, 0, '|', ROWS);
    mvvline(TOP, COLS - 1, '|', ROWS);
}

void NcursesExit(void) {
    nodelay(stdscr, FALSE); /* allow getch to block */
    mvprintw(LINES / 2, (COLS / 2) - strlen(EXIT_MESSAGE)/2, EXIT_MESSAGE);
    refresh();
    getch();
    endwin();
    exit(EXIT_SUCCESS);
}
