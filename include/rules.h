#ifndef rules_h
#define rules_h

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_audio.h>
#include "setting.h"
#include "objects.h"
#include "status.h"

/*�P�_�C���O�_����*/
void gameOverConditions(SDL_Renderer *render);

/* ����D��Ѿl�ɶ� */
Uint32 *snakeSuperModeCall(Uint32 interval, void *param);

#endif
