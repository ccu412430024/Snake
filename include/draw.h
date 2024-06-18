#ifndef draw_h
#define draw_h

#include <SDL.h>
#include "setting.h"
#include "objects.h"

/* 繪製蛇 */
void drawSnake(SDL_Renderer *render);

/* 畫實心圓函式，用於drawFood()、drawSnake() */
void drawFilledCircle(SDL_Renderer* render, int centerX, int centerY, int radius);

/* 畫空心圓函式，用於drawSnake() */
void drawHollowCircle(SDL_Renderer* render, int centerX, int centerY, int radius);

/* 畫食物 */
void drawFood(SDL_Renderer *render);

/* 畫道具 */
void drawGameProps(SDL_Renderer *render);

/* 繪製每一幀中畫面上的所有內容 */
void draw(SDL_Renderer *render);

#endif
