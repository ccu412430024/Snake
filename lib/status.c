#include "status.h"

/* 判斷遊戲狀態 */
bool isDone = false;
bool pause = false;
bool gameOver = false;
bool home = true;
bool superMode = false;

/* 分數 */
int score = 0;

/* 道具剩餘秒數 */
int superModeRemainTime = 0;

/* 紀錄已經產生過道具的分數 */
int scoreachieve = 0;

/* 蛇的移動速度 */
int speed = SNAKE_MOVE_INTERVAL;
