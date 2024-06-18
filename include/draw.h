#ifndef draw_h
#define draw_h

#include <SDL.h>
#include "setting.h"
#include "objects.h"

/* ø�s�D */
void drawSnake(SDL_Renderer *render);

/* �e��߶�禡�A�Ω�drawFood()�BdrawSnake() */
void drawFilledCircle(SDL_Renderer* render, int centerX, int centerY, int radius);

/* �e�Ť߶�禡�A�Ω�drawSnake() */
void drawHollowCircle(SDL_Renderer* render, int centerX, int centerY, int radius);

/* �e���� */
void drawFood(SDL_Renderer *render);

/* �e�D�� */
void drawGameProps(SDL_Renderer *render);

/* ø�s�C�@�V���e���W���Ҧ����e */
void draw(SDL_Renderer *render);

#endif
