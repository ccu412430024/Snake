#include "rules.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>


// 初始化 SDL 和音效系統
void initaudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }
    printf("Audio system initialized.\n");
}

// 關閉 SDL 和音效系統
void closeaudio() {
    Mix_CloseAudio();
    SDL_Quit();
    printf("Audio system closed.\n");
}

// 播放音效
void playdieSound() {
    Mix_Chunk *dieSound = Mix_LoadWAV("die.wav");
    if (dieSound == NULL) {
        printf("Failed to load die sound! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    // 設置音效音量，範圍是 0 到 MIX_MAX_VOLUME
    Mix_VolumeChunk(dieSound, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, dieSound, 0);
    SDL_Delay(1000);

    if (Mix_PlayChannel(-1, dieSound, 0) == -1) {
        printf("Failed to play die sound! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        printf("die sound played.\n");
    }
    Mix_FreeChunk(dieSound);
}



/*判斷遊戲是否結束*/
void gameOverConditions(SDL_Renderer *render){
    /* 超出邊界，遊戲結束 */
    if(superMode == false && (snake.pos[0].x < 0 || snake.pos[0].x >= SCREEN_WIDTH || snake.pos[0].y < 0 || snake.pos[0].y >= SCREEN_HEIGHT)){
        pause = true;
        gameOver = true;
        playdieSound();
        keepScore();
        continueOrHomePage();
    }

    /* 蛇頭碰到身體，遊戲結束 */
    for(int i = 1; i < snake.length; i ++){
        if(superMode == false && (snake.pos[0].x == snake.pos[i].x) && (snake.pos[0].y == snake.pos[i].y)){
            pause = true;
            gameOver = true;
            playdieSound();
            keepScore();
            continueOrHomePage();
        }
    }
}

/* 控制道具剩餘時間 */
Uint32 *snakeSuperModeCall(Uint32 interval, void *param){
    if(superModeRemainTime > 0){
        superMode = true;
        superModeRemainTime -= 100;
        speed = SNAKE_MOVE_INTERVAL / 2;
    }else{
        speed = SNAKE_MOVE_INTERVAL;
        superMode = false;
    }
    return interval;
}
