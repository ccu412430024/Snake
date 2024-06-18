#include "objects.h"

/* 初始化蛇的結構體 */
Snake snake;

/* 初始化蛇 */
void initSnake(){
    snake.length = INIT_LENGTH;    //初始長度為INIT_LENGTH
    snake.size = GRID_WIDTH;   //寬度為GRID_WIDTH
    snake.dir = SDLK_RIGHT;    //初始方向向右

    /* 隨機生成蛇頭座標，功能如randomPosition()，但加入限制使其不離邊界過近 */
    int XMin = INIT_LENGTH * (snake.size);
    int XMax = SCREEN_WIDTH - (INIT_LENGTH * (snake.size));
    snake.pos[0].x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH ;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT - GRID_WIDTH;
    snake.pos[0].y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH ;

    /* 設定蛇身座標 */
    for(int i = 1; i < snake.length; i++){
        snake.pos[i].x = snake.pos[i - 1].x - (snake.size);
        snake.pos[i].y = snake.pos[0].y;
    }
}

/* 初始化食物的結構體 */
Food food;

/* 初始化食物 */
void initFood(){
    food.size = GRID_WIDTH;
    for(int i = 0; i < MAX_FOOD_AMOUNT; i++){
        /* 隨機生成食物位置與顏色 */
        randomPosition(&(food.pos[i]));
        food.red[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
        food.green[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
        food.blue[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
    }
}

/* 初始化道具的結構體 */
GameProps gameProps;

/* 初始化道具 */
void initGameProps(){
    gameProps.size = GRID_WIDTH * GAME_PROPS_GRID_AMOUNT;
    gameProps.amount = INIT_GAME_PROPS_AMOUNT;
    for(int i = 0; i < MAX_GAME_PROPS_AMOUNT; i++){
        /* 隨機生成道具位置 */
        randomGamePropsPosition(&(gameProps.pos[i]));
    }
}

/* 在遊戲畫面範圍內隨機生成一組座標，座標皆為GRID_WIDTH的倍數，以確保蛇或食物在方格內 */
void randomPosition(SDL_Point *Position){
    int XMin = 0;
    int XMax = SCREEN_WIDTH;
    Position->x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT;
    Position->y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH;
}

/* 在遊戲畫面範圍內隨機生成一組座標，座標皆為GRID_WIDTH的倍數，以確保道具在方格內 */
void randomGamePropsPosition(SDL_Point *Position){
    int XMin = 0;
    int XMax = SCREEN_WIDTH - gameProps.size;
    Position->x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT - gameProps.size;
    Position->y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH;
}
