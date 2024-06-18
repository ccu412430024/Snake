#ifndef status_h
#define status_h

#include <stdbool.h>
#include "setting.h"

/* 判斷遊戲狀態 */
extern bool isDone;
extern bool pause;
extern bool gameOver;
extern bool home;
extern bool superMode;

/* 分數 */
extern int score;

/* 道具剩餘秒數 */
extern int superModeRemainTime;

/* 紀錄已經產生過道具的分數 */
extern int scoreachieve;

/* 蛇的移動速度 */
extern int speed;

#endif
