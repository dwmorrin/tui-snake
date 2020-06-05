#ifndef FIELD
#define FIELD

#include "field.h"

int FieldRandX(void) {
    return (rand() % INNER_COLS) + 1;
}
int FieldRandY(void) {
    return (rand() % ROWS) + TOP;
}
void FieldDropContent(int field[MAX_ROWS][MAX_COLS], int content, int n, int color, int symbol) {
    int i = 0;
    while (i < n) {
        int x = FieldRandX();
        int y = FieldRandY();
        if (field[y][x] == EMPTY) {
            field[y][x] = content;
            attron(COLOR_PAIR(color));
            mvaddch(y, x, symbol);
            attroff(COLOR_PAIR(color));
            ++i;
        }
    }
}

void FieldPlaceHContent(int field[MAX_ROWS][MAX_COLS], int content, int x, int y, int n, int color, int symbol) {
    int i = 0;
    while (i < n) {
        field[y][x + i] = content;
        attron(COLOR_PAIR(color));
        mvaddch(y, x + i, symbol);
        attroff(COLOR_PAIR(color));
        ++i;
    }
}
void FieldPlaceVContent(int field[MAX_ROWS][MAX_COLS], int content, int x, int y, int n, int color, int symbol) {
    int i = 0;
    while (i < n) {
        field[y + i][x] = content;
        attron(COLOR_PAIR(color));
        mvaddch(y + i, x, symbol);
        attroff(COLOR_PAIR(color));
        ++i;
    }
}
#endif
