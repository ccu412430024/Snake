#include "initialize.h"

/* ��l�ƹC�����e */
void init(){
    /* ���ơB�D��ɪ��B�w�F�����ơB�t���k�s */
    score = 0;
    superModeRemainTime = 0;
    scoreachieve = 0;
    speed = SNAKE_MOVE_INTERVAL;

    /* ��l�ƳD�έ��� */
    initSnake();
    initFood();
    initGameProps();
}
