#ifndef objects_h
#define objects_h

#include <SDL.h>
#include "setting.h"


/* �w�q�D�����c�� */
typedef struct Snake{
    SDL_Point pos[MAX_LENGTH];  //�C�`���骺��m
    int length; //�D������(�`��)
    int size;   //�C�`���骺�e�סA�P�ɤ]�O����
    int dir;    //�D�Y���ʤ�V
}Snake;


/*�w�q���������c��*/
typedef struct Food{
    SDL_Point pos[MAX_FOOD_AMOUNT]; //�����`��
    int size;
    int red[MAX_FOOD_AMOUNT];
    int green[MAX_FOOD_AMOUNT];
    int blue[MAX_FOOD_AMOUNT];
}Food;

/*�w�q�D�㪺���c��*/
typedef struct GameProps{
    SDL_Point pos[MAX_GAME_PROPS_AMOUNT]; //�D���`��
    int size;
    int amount;
}GameProps;

/* �ŧi�D�����c�� */
extern Snake snake;

/* �ŧi���������c�� */
extern Food food;

/* �ŧi�D�㪺���c�� */
extern GameProps gameProps;

/* �b�C���e���d���H���ͦ��@�ծy�СA�y�ЬҬ�GRID_WIDTH�����ơA�H�T�O�D�έ����b��椺 */
void randomPosition(SDL_Point *Position);

/* �b�C���e���d���H���ͦ��@�ծy�СA�y�ЬҬ�GRID_WIDTH�����ơA�H�T�O�D��b��椺 */
void randomGamePropsPosition(SDL_Point *Position);

#endif
