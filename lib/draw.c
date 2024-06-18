#include "draw.h"

/* 繪製蛇 */
void drawSnake(SDL_Renderer *render){
    int radius = snake.size / 2;
    SDL_SetRenderDrawColor(render, 63, 101, 32, 255);   //墨綠色
    for(int i = 1; i < snake.length; i++){
        /********讓蛇身非空心，完全不透明**********
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        drawFilledCircle(render, snake.pos[0].x + radius, snake.pos[0].y + radius, radius - 1);
        SDL_SetRenderDrawColor(render, 63, 101, 32, 255);
        ********************************************/
        drawHollowCircle(render, snake.pos[i].x + radius, snake.pos[i].y + radius, radius - 1);
    }
    SDL_SetRenderDrawColor(render, 63, 101, 32, 255);   //墨綠色
    drawFilledCircle(render, snake.pos[0].x + radius, snake.pos[0].y + radius, radius - 1);
}

/* 畫實心圓函式，用於drawFood()、drawSnake() */
void drawFilledCircle(SDL_Renderer* render, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            /* 找出圓內的點，以畫點方式形成圓 */
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(render, centerX + dx, centerY + dy);
            }
        }
    }
}

/* 畫空心圓函式，用於drawSnake() */
void drawHollowCircle(SDL_Renderer* render, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            /* 找出圓內的點，以畫點方式形成圓 */
            if((radius - sqrt(dx*dx + dy*dy)) >= 0 && (radius - sqrt(dx*dx + dy*dy)) <= radius / 2)
            {
                SDL_RenderDrawPoint(render, centerX + dx, centerY + dy);
            }
        }
    }
}

/* 畫食物 */
void drawFood(SDL_Renderer *render){
    int radius = food.size / 2;
    for(int i = 0; i < MAX_FOOD_AMOUNT; i++){
        SDL_SetRenderDrawColor(render, food.red[i], food.green[i], food.blue[i], 255);
        drawFilledCircle(render, food.pos[i].x + radius, food.pos[i].y + radius, radius - 1);
    }
}

/* 畫道具 */
void drawGameProps(SDL_Renderer *render){
    /* 載入遊戲道具圖片 */
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

/* 繪製每一幀中畫面上的所有內容 */
void draw(SDL_Renderer *render){
    /* 繪製地圖背景(白色) */
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);

    /* 繪製框線(灰色) */
    SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
    for(int i = 0; i < SCREEN_WIDTH; i++){
        SDL_RenderDrawLine(render, 0, i * GRID_WIDTH, SCREEN_WIDTH, i * GRID_WIDTH);
    }
    for(int i = 0; i < SCREEN_HEIGHT; i++){
        SDL_RenderDrawLine(render, i * GRID_WIDTH, 0, i * GRID_WIDTH, SCREEN_HEIGHT);
    }

    /* 繪製食物、道具、蛇 */
    drawFood(render);
    drawGameProps(render);
    drawSnake(render);
    printScore(render);
    /* 將繪製之內容放上window */
    SDL_RenderPresent(render);
}
