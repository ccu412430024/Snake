#ifndef move_h
#define move_h

#include <SDL.h>
#include "setting.h"
#include "status.h"
#include "objects.h"

/* Timer�N�CSNAKE_MOVE_INTERVAL�@����榹��� */
Uint32 *snakeMoveCall(Uint32 interval, SDL_Renderer *render);

/* �B�z�D�Y�γD������m�A�w�ɾ��N�z�LsnakeMoveCall�A�CSNAKE_MOVE_INTERVAL�@����榹��� */
void moveSnake();

/* �P�_��ث���Q���U */
void keyDownEvent(SDL_KeyboardEvent *ev);

#endif
