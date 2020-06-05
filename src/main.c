#include <time.h>

#include "tuigame.h"
#include "snake.h"
#include "field.h"

#define SPEED_DEC 20000

#define FOOD_LEN 10
int main() {
    NcursesInit();

    srand(time(0));
    int food = FOOD_LEN,
        score = 0,
        delay = DELAY,
        userInput = ERR;
    bool run = true;
    int field[MAX_ROWS][MAX_COLS] = {0};
    FieldPlaceVContent(field, WALL, 9, 9, 10, WHITE, '|');
    FieldPlaceHContent(field, WALL, 12, 9, 10, WHITE, '"');
    FieldPlaceHContent(field, WALL, 15, 11, 10, WHITE, '"');
    FieldDropContent(field, FOOD, FOOD_LEN, YELLOW, '$');
    FieldDropContent(field, POISON, 20, GREEN, '!');
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    struct Snake *snake = &snake_;
    SnakeInit(snake);
    while (run) {
        if ((userInput = getch()) != ERR) { /* ERR is the default */
            switch (userInput) {
                case 'q':
                    run = false;
                    break;
                case UP:
                case DOWN:
                case LEFT:
                case RIGHT:
                    snake->direction = userInput;
                    break;
            }
        }
        gettimeofday(&t1, NULL);
        if (TimeGetElapsed(t0, t1) < delay) {
            continue;
        }
        SnakePrint(snake, ' ');
        int eaten = SnakeEat(snake, field);
        if (eaten != EMPTY) {
            if (eaten == FOOD) {
                ++score;
                --food;
                if (food == 0) {
                    FieldDropContent(field, FOOD, FOOD_LEN, YELLOW, '$');
                    FieldDropContent(field, FOOD, 3, GREEN, '!');
                    food = FOOD_LEN;
                    delay -= SPEED_DEC;
                }
            } else if (eaten == POISON) {
                --score;
            } else if (eaten == WALL) {
                run = false;
            }
        }
        if (! SnakeMove(snake)) {
            run = false;
        }
        if (SnakeOutOfBounds(snake)) {
            run = false;
        }
        SnakePrint(snake, '0');
        mvprintw(0, 10, "Score: %4d | Head: (%2d, %2d) | Cols: %d | Lines: %d",
                score, snake->head->x, snake->head->y, COLS, LINES);
        gettimeofday(&t0, NULL);
    }
    NcursesExit();
    return 1;
}
