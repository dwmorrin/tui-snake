#ifndef TUIGAME
#define TUIGAME

#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>

#define BANNER_STRING "Snake"
#define CEILING 3
//#define DELAY 90000 /* fast */
#define DELAY 130000 /* med */
//#define DELAY 180000 /* slow */
#define EXIT_MESSAGE "DONE press any key"
#define TOP (CEILING + 1)
#define BOTTOM (LINES - 1)
#define ROWS (BOTTOM - TOP)
#define INNER_COLS (COLS - 2)
#define MAX_ROWS 1000
#define MAX_COLS 1000

enum {
    WHITE, RED, YELLOW, GREEN
};
long long TimeGetElapsed(struct timeval t0, struct timeval t1);
void NcursesCenterMessage(const char*);
void NcursesInit(void);
void NcursesExit(void);

#endif
