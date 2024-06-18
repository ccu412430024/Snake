#ifndef move_h
#define move_h

#include <SDL.h>
#include "setting.h"
#include "status.h"
#include "objects.h"

/* Timer將每SNAKE_MOVE_INTERVAL毫秒執行此函數 */
Uint32 *snakeMoveCall(Uint32 interval, SDL_Renderer *render);

/* 處理蛇頭及蛇身的位置，定時器將透過snakeMoveCall，每SNAKE_MOVE_INTERVAL毫秒執行此函數 */
void moveSnake();

/* 判斷何種按鍵被按下 */
void keyDownEvent(SDL_KeyboardEvent *ev);

#endif
