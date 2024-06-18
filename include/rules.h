#ifndef rules_h
#define rules_h

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_audio.h>
#include "setting.h"
#include "objects.h"
#include "status.h"

/*判斷遊戲是否結束*/
void gameOverConditions(SDL_Renderer *render);

/* 控制道具剩餘時間 */
Uint32 *snakeSuperModeCall(Uint32 interval, void *param);

#endif
