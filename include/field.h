#include "tuigame.h"
#include "snake.h"

int FieldRandX(void);
int FieldRandY(void);
void FieldDropContent(int[MAX_ROWS][MAX_COLS], int, int, int, int );
void FieldPlaceHContent(int[MAX_ROWS][MAX_COLS], int, int, int, int, int, int);
void FieldPlaceVContent(int[MAX_ROWS][MAX_COLS], int, int, int, int, int, int);
