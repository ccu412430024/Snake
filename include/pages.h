#ifndef pages_h
#define pages_h

#include <SDL.h>
#include <SDL_image.h>
#include "setting.h"
#include "status.h"

/* �D�e�� */
void homePage(SDL_Renderer *render);

/* �D�e���I�� */
void drawHomePage(SDL_Renderer *render);

/* �鱼�C���ɪ��e�� */
void drawLosePage(SDL_Renderer *render);

/* �C��������n�~��Φ^��D�e�� */
void continueOrHomePage();

#endif
