#include "move.h"

/* Timer將每SNAKE_MOVE_INTERVAL毫秒執行此函數 */
Uint32 *snakeMoveCall(Uint32 interval, SDL_Renderer *render){
    if((pause == false) && (gameOver == false)){
        moveSnake();
        eatGameProps();
        eatFood();
        gameOverConditions(render);
    }
        return speed;
}

/* 處理蛇頭及蛇身的位置，定時器將透過snakeMoveCall，每SNAKE_MOVE_INTERVAL毫秒執行此函數 */
void moveSnake(){
    /* 此節蛇身位置即為前一節蛇身位置 */
    for(int i = snake.length - 1; i > 0; i--){
        snake.pos[i] = snake.pos[i - 1];
    }
    /*根據目前蛇頭方向決定移動方向*/
    switch(snake.dir){
        case SDLK_UP:
            snake.pos[0].y -= snake.size; //蛇頭向上
            if(superMode == true && snake.pos[0].y < 0){
                snake.pos[0].y = SCREEN_HEIGHT - snake.size;
            }
            break;
        case SDLK_DOWN:
            snake.pos[0].y += snake.size; //蛇頭向下
            if(superMode == true && snake.pos[0].y >= SCREEN_HEIGHT){
                snake.pos[0].y = 0;
            }
            break;
        case SDLK_LEFT:
            snake.pos[0].x -= snake.size; //蛇頭向左
            if(superMode == true && snake.pos[0].x < 0){
                snake.pos[0].x = SCREEN_WIDTH - snake.size;
            }
            break;
        case SDLK_RIGHT:
            snake.pos[0].x += snake.size; //蛇頭向右
            if(superMode == true && snake.pos[0].x >= SCREEN_WIDTH){
                snake.pos[0].x = 0;
            }
            break;
    }
}

/* 判斷何種按鍵被按下 */
void keyDownEvent(SDL_KeyboardEvent *ev){
    switch(ev->keysym.sym){
        case SDLK_UP: case SDLK_w:
            snake.dir = SDLK_UP;    //方向鍵上及W鍵，蛇頭向上
            break;
        case SDLK_DOWN: case SDLK_s:
            snake.dir = SDLK_DOWN;  //方向鍵下及S鍵，蛇頭向下
            break;
        case SDLK_LEFT: case SDLK_a:
            snake.dir = SDLK_LEFT;  //方向鍵左及A鍵，蛇頭向左
            break;
        case SDLK_RIGHT: case SDLK_d:
            snake.dir = SDLK_RIGHT; //方向鍵右及D鍵，蛇頭向右
            break;
        case SDLK_SPACE:    //空白鍵暫停遊戲
            pause = !pause;
            break;
    }
}
