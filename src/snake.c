#include "snake.h"

void SnakeInit(struct Snake *s) {
    s->head = (struct BodyBit*) malloc(sizeof (struct BodyBit));
    s->direction = RIGHT;
    s->head->x = COLS / 2;
    s->head->y = LINES / 2;
    s->head->next = NULL;
}
// returns false if head collides with body
bool BodyMove(struct BodyBit *b, int x, int y, struct BodyBit *head) {
    if (b != head && b->x == head->x && b->y == head->y) {
        return false;
    }
    bool result = true;
    if (b->next != NULL) {
        result = BodyMove(b->next, b->x, b->y, head);
    }
    b->x = x;
    b->y = y;
    return result;
}
void BodyGrow(struct BodyBit *b) {
    if (b->next == NULL) {
        b->next = (struct BodyBit*) malloc(sizeof (struct BodyBit));
        b->next->x = b->next->y = 0;
        b->next->next = NULL;
        return;
    }
    BodyGrow(b->next);
}
void BodyShrink(struct BodyBit *b) {
    if (b->next == NULL) {
        return;
    }
    if (b->next->next == NULL) {
        free(b->next->next);
        b->next = NULL;
        return;
    }
    BodyShrink(b->next);
}
void SnakePrint(struct Snake *s, char c) {
    struct BodyBit *b = s->head;
    attron(COLOR_PAIR(1));
    while (b != NULL) {
        mvaddch(b->y, b->x, c);
        attroff(COLOR_PAIR(1));
        b = b->next;
    }
}

bool SnakeMove(struct Snake *s) {
    int x = s->head->x,
        y = s->head->y;
    switch (s->direction) {
        case UP:    --y; break;
        case LEFT:  --x; break;
        case DOWN:  ++y; break;
        case RIGHT: ++x; break;
    }
    return BodyMove(s->head, x, y, s->head);
}

bool SnakeOutOfBounds(struct Snake *s) {
    if (
        s->head->x >= COLS - 1 ||
        s->head->x <= 0        ||
        s->head->y <= CEILING  ||
        s->head->y >= BOTTOM
    ) {
        return true;
    }
    return false;
}
int SnakeEat(struct Snake *s, int field[MAX_ROWS][MAX_COLS]) {
    int eaten = field[s->head->y][s->head->x];
    if (eaten == FOOD) {
        field[s->head->y][s->head->x] = EMPTY;
        BodyGrow(s->head);
    }
    if (eaten == POISON) {
        field[s->head->y][s->head->x] = EMPTY;
        BodyShrink(s->head);
    }
    return eaten;
}

