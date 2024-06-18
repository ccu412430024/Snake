#include "eat.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>

// 初始化 SDL 和音效系統
void initAudio() {
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
void closeAudio() {
    Mix_CloseAudio();
    SDL_Quit();
    printf("Audio system closed.\n");
}

// 播放音效
void playEatSound() {
    Mix_Chunk *eatSound = Mix_LoadWAV("eat.wav");
    if (eatSound == NULL) {
        printf("Failed to load eat sound! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    // 設置音效音量，範圍是 0 到 MIX_MAX_VOLUME
    Mix_VolumeChunk(eatSound, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, eatSound, 0);
    SDL_Delay(100);

    if (Mix_PlayChannel(-1, eatSound, 0) == -1) {
        printf("Failed to play eat sound! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        printf("Eat sound played.\n");
    }
    Mix_FreeChunk(eatSound);
}

void playhitSound() {
    Mix_Chunk *hitSound = Mix_LoadWAV("hit.wav");
    if (hitSound == NULL) {
        printf("Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    // 設置音效音量，範圍是 0 到 MIX_MAX_VOLUME
    Mix_VolumeChunk(hitSound, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, hitSound, 0);
    SDL_Delay(110);

    if (Mix_PlayChannel(-1,hitSound, 0) == -1) {
        printf("Failed to play hit sound! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        printf("hit sound played.\n");
    }
    Mix_FreeChunk(hitSound);
}

void eatFood(){
    printf("Checking food collision...\n");
    for(int i = 0; i < MAX_FOOD_AMOUNT; i++){
        if((snake.pos[0].x == food.pos[i].x) && (snake.pos[0].y == food.pos[i].y)){
            printf("Food eaten at position (%d, %d)\n", food.pos[i].x, food.pos[i].y);
            randomPosition(&(food.pos[i]));
            food.red[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            food.green[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            food.blue[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            score += FOOD_POINT;
            playEatSound(); // 播放音效
            if(snake.length == MAX_LENGTH){
                break;
            }
            snake.pos[snake.length] = snake.pos[snake.length - 1];
            snake.length++;
        }
        if(superMode == true && food.pos[i].x >= (snake.pos[0].x - snake.size*2) && food.pos[i].x <= (snake.pos[0].x + snake.size*2) && food.pos[i].y >= (snake.pos[0].y - snake.size*2) && food.pos[i].y <= (snake.pos[0].y + snake.size*2)){
            printf("Super mode food eaten at position (%d, %d)\n", food.pos[i].x, food.pos[i].y);
            randomPosition(&(food.pos[i]));
            food.red[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            food.green[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            food.blue[i] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
            score += FOOD_POINT;
            playhitSound(); // 播放音效
            if(snake.length == MAX_LENGTH){
                break;
            }
            snake.pos[snake.length] = snake.pos[snake.length - 1];
            snake.length++;
        }
        if((score > scoreachieve) && (score % GET_GAME_PROPS_SCORE == 0 ) && (gameProps.amount < MAX_GAME_PROPS_AMOUNT)){
            gameProps.amount++;
            scoreachieve = score;
        }else if(score % GET_GAME_PROPS_SCORE == 0){
            scoreachieve = score;
        }
    }
}

void eatGameProps(){
    for(int i = 0; i < gameProps.amount; i++){
        if((snake.pos[0].x >= gameProps.pos[i].x) && (snake.pos[0].x < gameProps.pos[i].x + gameProps.size) && (snake.pos[0].y >= gameProps.pos[i].y) && (snake.pos[0].y < gameProps.pos[i].y + gameProps.size)){
            superModeRemainTime += SUPER_MODE_TIME;
            randomGamePropsPosition(&(gameProps.pos[i]));
            gameProps.amount--;
        }
    }
}
