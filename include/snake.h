#ifndef SNAKEGAME
#define SNAKEGAME

#include "tuigame.h"

#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

enum {
    EMPTY, FOOD, POISON, WALL
};

struct Snake {
    struct BodyBit *head;
    int direction;
} snake_;

struct Food {
    int x, y;
};

struct BodyBit {
    int x, y;
    struct BodyBit *next;
};

void BodyGrow(struct BodyBit*);
bool BodyMove(struct BodyBit*, int, int, struct BodyBit*);
void BodyShrink(struct BodyBit *b);
int  SnakeEat(struct Snake*, int[MAX_ROWS][MAX_COLS]);
void SnakeInit(struct Snake*);
bool SnakeMove(struct Snake*);
bool SnakeOutOfBounds(struct Snake*);
void SnakePrint(struct Snake*, char);

#endif
