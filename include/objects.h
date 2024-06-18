#ifndef objects_h
#define objects_h

#include <SDL.h>
#include "setting.h"


/* 定義蛇的結構體 */
typedef struct Snake{
    SDL_Point pos[MAX_LENGTH];  //每節身體的位置
    int length; //蛇的長度(節數)
    int size;   //每節身體的寬度，同時也是長度
    int dir;    //蛇頭移動方向
}Snake;


/*定義食物的結構體*/
typedef struct Food{
    SDL_Point pos[MAX_FOOD_AMOUNT]; //食物總數
    int size;
    int red[MAX_FOOD_AMOUNT];
    int green[MAX_FOOD_AMOUNT];
    int blue[MAX_FOOD_AMOUNT];
}Food;

/*定義道具的結構體*/
typedef struct GameProps{
    SDL_Point pos[MAX_GAME_PROPS_AMOUNT]; //道具總數
    int size;
    int amount;
}GameProps;

/* 宣告蛇的結構體 */
extern Snake snake;

/* 宣告食物的結構體 */
extern Food food;

/* 宣告道具的結構體 */
extern GameProps gameProps;

/* 在遊戲畫面範圍內隨機生成一組座標，座標皆為GRID_WIDTH的倍數，以確保蛇或食物在方格內 */
void randomPosition(SDL_Point *Position);

/* 在遊戲畫面範圍內隨機生成一組座標，座標皆為GRID_WIDTH的倍數，以確保道具在方格內 */
void randomGamePropsPosition(SDL_Point *Position);

#endif
