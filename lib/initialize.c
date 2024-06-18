#include "initialize.h"

/* 初始化遊戲內容 */
void init(){
    /* 分數、道具時長、已達成分數、速度歸零 */
    score = 0;
    superModeRemainTime = 0;
    scoreachieve = 0;
    speed = SNAKE_MOVE_INTERVAL;

    /* 初始化蛇及食物 */
    initSnake();
    initFood();
    initGameProps();
}
