#include "objects.h"

/* ��l�ƳD�����c�� */
Snake snake;

/* ��l�ƳD */
void initSnake(){
    snake.length = INIT_LENGTH;    //��l���׬�INIT_LENGTH
    snake.size = GRID_WIDTH;   //�e�׬�GRID_WIDTH
    snake.dir = SDLK_RIGHT;    //��l��V�V�k

    /* �H���ͦ��D�Y�y�СA�\��prandomPosition()�A���[�J����Ϩ䤣����ɹL�� */
    int XMin = INIT_LENGTH * (snake.size);
    int XMax = SCREEN_WIDTH - (INIT_LENGTH * (snake.size));
    snake.pos[0].x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH ;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT - GRID_WIDTH;
    snake.pos[0].y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH ;

    /* �]�w�D���y�� */
    for(int i = 1; i < snake.length; i++){
        snake.pos[i].x = snake.pos[i - 1].x - (snake.size);
        snake.pos[i].y = snake.pos[0].y;
    }
}

/* ��l�ƭ��������c�� */
Food food;

/* ��l�ƭ��� */
void initFood(){
    food.size = GRID_WIDTH;
    for(int i = 0; i < MAX_FOOD_AMOUNT; i++){
        /* �H���ͦ�������m�P�C�� */
        randomPosition(&(food.pos[i]));
        food.red[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
        food.green[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
        food.blue[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
    }
}

/* ��l�ƹD�㪺���c�� */
GameProps gameProps;

/* ��l�ƹD�� */
void initGameProps(){
    gameProps.size = GRID_WIDTH * GAME_PROPS_GRID_AMOUNT;
    gameProps.amount = INIT_GAME_PROPS_AMOUNT;
    for(int i = 0; i < MAX_GAME_PROPS_AMOUNT; i++){
        /* �H���ͦ��D���m */
        randomGamePropsPosition(&(gameProps.pos[i]));
    }
}

/* �b�C���e���d���H���ͦ��@�ծy�СA�y�ЬҬ�GRID_WIDTH�����ơA�H�T�O�D�έ����b��椺 */
void randomPosition(SDL_Point *Position){
    int XMin = 0;
    int XMax = SCREEN_WIDTH;
    Position->x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT;
    Position->y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH;
}

/* �b�C���e���d���H���ͦ��@�ծy�СA�y�ЬҬ�GRID_WIDTH�����ơA�H�T�O�D��b��椺 */
void randomGamePropsPosition(SDL_Point *Position){
    int XMin = 0;
    int XMax = SCREEN_WIDTH - gameProps.size;
    Position->x = ((rand() % (XMax - XMin + 1) + XMin) / GRID_WIDTH) * GRID_WIDTH;
    int YMin = 0;
    int YMax = SCREEN_HEIGHT - gameProps.size;
    Position->y = ((rand() % (YMax - YMin + 1) + YMin) / GRID_WIDTH) * GRID_WIDTH;
}
