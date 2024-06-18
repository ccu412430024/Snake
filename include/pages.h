#ifndef pages_h
#define pages_h

#include <SDL.h>
#include <SDL_image.h>
#include "setting.h"
#include "status.h"

/* 主畫面 */
void homePage(SDL_Renderer *render);

/* 主畫面背景 */
void drawHomePage(SDL_Renderer *render);

/* 輸掉遊戲時的畫面 */
void drawLosePage(SDL_Renderer *render);

/* 遊戲結束後要繼續或回到主畫面 */
void continueOrHomePage();

#endif
