#include "pages.h"

/* 主畫面 */
void homePage(SDL_Renderer *render){
    /* 暫停遊戲 */
    pause = true;

    /* 載入主畫面圖片 */
    drawHomePage(render);

    /* 宣告事件變數 */
    SDL_Event ev;

    /* 處理事件 */
    while(home == true && isDone == false){
        SDL_PollEvent(&ev);
        switch(ev.type){
            case SDL_KEYDOWN:
                if(ev.key.keysym.sym == SDLK_RETURN){
                    /* Enter鍵被按下，進入遊戲 */
                    home = false;
                    pause = false;
                }
                if(ev.key.keysym.sym == SDLK_r){
                    home = false;
                    ranking(render);
                    drawHomePage(render);
                }
                break;
            case SDL_QUIT:
                isDone = true; //關閉鍵被按下，結束遊戲
                break;
        }
    }
}

/* 主畫面背景 */
void drawHomePage(SDL_Renderer *render){
    /* 載入主畫面圖片 */
    SDL_Texture *backGround = IMG_LoadTexture(render, "img/snake.jpg");
    SDL_RenderCopy(render, backGround, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_DestroyTexture(backGround);
}


/* 輸掉遊戲時的畫面 */
void drawLosePage(SDL_Renderer *render){
    SDL_Texture *backGround = IMG_LoadTexture(render, "img/lose.png");
    SDL_RenderCopy(render, backGround, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_DestroyTexture(backGround);
}

/* 遊戲結束後要繼續或回到主畫面 */
void continueOrHomePage(){
    /* 宣告事件變數 */
    SDL_Event ev;
    /* 處理事件 */
    while(gameOver){
        //SDL_Log("drawLosePage");
        SDL_PollEvent(&ev);
        if(ev.type == SDL_QUIT){
            isDone = true;
            break;
        }
        switch(ev.key.keysym.sym){
            case SDLK_RETURN:
                init();
                pause = false;
                gameOver = false;
                break;
            case SDLK_h:
                gameOver = false;
                home = true;
                init();
                break;
        }
    }
}
