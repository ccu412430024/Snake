#include "status.h"

/* �P�_�C�����A */
bool isDone = false;
bool pause = false;
bool gameOver = false;
bool home = true;
bool superMode = false;

/* ���� */
int score = 0;

/* �D��Ѿl��� */
int superModeRemainTime = 0;

/* �����w�g���͹L�D�㪺���� */
int scoreachieve = 0;

/* �D�����ʳt�� */
int speed = SNAKE_MOVE_INTERVAL;
