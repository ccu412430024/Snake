#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_audio.h>
#include "setting.h"
#include "status.h"
#include "move.h"
#include "rules.h"

void initAudio();
void closeAudio();

/* Debug專用，Timer將每1000毫秒執行此函數 */
Uint32 *debugCall(Uint32 interval, void *param){
    SDL_Log("isDone: %d", isDone);
    SDL_Log("pause: %d", pause);
    SDL_Log("gameOver: %d", gameOver);
    SDL_Log("home: %d", home);
    SDL_Log("superMode: %d", superMode);
    SDL_Log("score: %d", score);
    SDL_Log("superModeRemainTime: %d", superModeRemainTime);
    SDL_Log("scoreachieve: %d", scoreachieve);
    SDL_Log("speed: %d", speed);
    SDL_Log("*************");
    return interval;
}


int main(int argc, char *argv[]){
    initAudio();

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);  // Initialize SDL with audio support
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *backgroundMusic = Mix_LoadMUS("BGM.wav");  // Load the background music
    Mix_PlayMusic(backgroundMusic, -1);  // Play the music indefinitely

    /* 設定亂數種子，用於randomPosition() */
    srand(time(NULL));

    /* 檢查SDL是否初始化成功 */
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | IMG_INIT_JPG | IMG_INIT_PNG)){
        SDL_Log("Can not init sdl2.\n");
        return -1;
    }
    if(TTF_Init() == -1){
        SDL_Log("Can not init sdl2.\n");
        return -1;
    }
    /* 初始化window及render */
    SDL_Window *window = NULL;
    SDL_Renderer *render = NULL;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &render);
    SDL_SetWindowTitle(window, "Snake");

    /* 初始化遊戲 */
    init();

    /* 新增Timer，每SNAKE_MOVE_INTERVAL毫秒移動一次蛇頭方向 */
    SDL_TimerID TimerID = SDL_AddTimer(speed, snakeMoveCall, render);

    /*新增Timer,計算道具有效時間*/
    SDL_AddTimer(100, snakeSuperModeCall, NULL);

    /* Debug專用，用於觀察遊戲狀態 */
    SDL_AddTimer(1000, debugCall, NULL);

    /* 執行直到遊戲結束 */
    while(!isDone){
        /* 記錄遊戲運行時的時間 */
        Uint32 begTime = SDL_GetTicks();

        /* 宣告事件變數 */
        SDL_Event ev;

        /* 主頁 */
        if(home == true){
            homePage(render);
        }

        /* 遊戲內容 */
        if(pause == false){
            draw(render);
        }

        if(gameOver == true){
            drawLosePage(render);
        }

        /* 處理事件，直到目前無須要處裡的事件為止 */
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_QUIT:
                    isDone = true;  //關閉鍵被按下，結束遊戲
                    keepScore();
                    break;
                case SDL_KEYDOWN:
                    keyDownEvent(&ev.key); //鍵盤按鍵被按下，在keyDownEvent()中近一步處理
                    break;
            }
        }

        /* 計算程式運行後還剩多少時間，使用Delay固定幀數 */
        Uint32 elapsed = SDL_GetTicks() - begTime;
        int delay = 1000 / FPS - elapsed;

        /* Debug專用，用於觀察delay */
        SDL_Log("%d", delay);

        if(delay > 0) SDL_Delay(delay);
    }
    /* 刪除window、render，結束IMG、SDL */
    closeAudio();
    Mix_FreeMusic(backgroundMusic);  // Free the music
    Mix_CloseAudio();  // Close the SDL_mixer
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_RemoveTimer(TimerID);
    IMG_Quit;
    SDL_Quit;
    return 0;
}
