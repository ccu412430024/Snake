#include "draw.h"

/* ø�s�D */
void drawSnake(SDL_Renderer *render){
    int radius = snake.size / 2;
    SDL_SetRenderDrawColor(render, 63, 101, 32, 255);   //�����
    for(int i = 1; i < snake.length; i++){
        /********���D���D�ŤߡA�������z��**********
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        drawFilledCircle(render, snake.pos[0].x + radius, snake.pos[0].y + radius, radius - 1);
        SDL_SetRenderDrawColor(render, 63, 101, 32, 255);
        ********************************************/
        drawHollowCircle(render, snake.pos[i].x + radius, snake.pos[i].y + radius, radius - 1);
    }
    SDL_SetRenderDrawColor(render, 63, 101, 32, 255);   //�����
    drawFilledCircle(render, snake.pos[0].x + radius, snake.pos[0].y + radius, radius - 1);
}

/* �e��߶�禡�A�Ω�drawFood()�BdrawSnake() */
void drawFilledCircle(SDL_Renderer* render, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            /* ��X�ꤺ���I�A�H�e�I�覡�Φ��� */
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(render, centerX + dx, centerY + dy);
            }
        }
    }
}

/* �e�Ť߶�禡�A�Ω�drawSnake() */
void drawHollowCircle(SDL_Renderer* render, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            /* ��X�ꤺ���I�A�H�e�I�覡�Φ��� */
            if((radius - sqrt(dx*dx + dy*dy)) >= 0 && (radius - sqrt(dx*dx + dy*dy)) <= radius / 2)
            {
                SDL_RenderDrawPoint(render, centerX + dx, centerY + dy);
            }
        }
    }
}

/* �e���� */
void drawFood(SDL_Renderer *render){
    int radius = food.size / 2;
    for(int i = 0; i < MAX_FOOD_AMOUNT; i++){
        SDL_SetRenderDrawColor(render, food.red[i], food.green[i], food.blue[i], 255);
        drawFilledCircle(render, food.pos[i].x + radius, food.pos[i].y + radius, radius - 1);
    }
}

/* �e�D�� */
void drawGameProps(SDL_Renderer *render){
    /* ���J�C���D��Ϥ� */
    SDL_Texture *gamePropIcon = IMG_LoadTexture(render, "img/gameprops.png");
    SDL_Rect gamePropIconRect;
    for(int i = 0; i < gameProps.amount; i++){
        gamePropIconRect.x = gameProps.pos[i].x;
        gamePropIconRect.y = gameProps.pos[i].y;
        gamePropIconRect.h = GRID_WIDTH * 2;
        gamePropIconRect.w = GRID_WIDTH * 2;
        SDL_RenderCopy(render, gamePropIcon, NULL, &gamePropIconRect);
    }
    //SDL_RenderPresent(render);
    SDL_DestroyTexture(gamePropIcon);
}

/* ø�s�C�@�V���e���W���Ҧ����e */
void draw(SDL_Renderer *render){
    /* ø�s�a�ϭI��(�զ�) */
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);

    /* ø�s�ؽu(�Ǧ�) */
    SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
    for(int i = 0; i < SCREEN_WIDTH; i++){
        SDL_RenderDrawLine(render, 0, i * GRID_WIDTH, SCREEN_WIDTH, i * GRID_WIDTH);
    }
    for(int i = 0; i < SCREEN_HEIGHT; i++){
        SDL_RenderDrawLine(render, i * GRID_WIDTH, 0, i * GRID_WIDTH, SCREEN_HEIGHT);
    }

    /* ø�s�����B�D��B�D */
    drawFood(render);
    drawGameProps(render);
    drawSnake(render);
    printScore(render);
    /* �Nø�s�����e��Wwindow */
    SDL_RenderPresent(render);
}
