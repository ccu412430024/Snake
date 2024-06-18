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

/* Debug�M�ΡATimer�N�C1000�@����榹��� */
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

    /* �]�w�üƺؤl�A�Ω�randomPosition() */
    srand(time(NULL));

    /* �ˬdSDL�O�_��l�Ʀ��\ */
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | IMG_INIT_JPG | IMG_INIT_PNG)){
        SDL_Log("Can not init sdl2.\n");
        return -1;
    }
    if(TTF_Init() == -1){
        SDL_Log("Can not init sdl2.\n");
        return -1;
    }
    /* ��l��window��render */
    SDL_Window *window = NULL;
    SDL_Renderer *render = NULL;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &render);
    SDL_SetWindowTitle(window, "Snake");

    /* ��l�ƹC�� */
    init();

    /* �s�WTimer�A�CSNAKE_MOVE_INTERVAL�@���ʤ@���D�Y��V */
    SDL_TimerID TimerID = SDL_AddTimer(speed, snakeMoveCall, render);

    /*�s�WTimer,�p��D�㦳�Įɶ�*/
    SDL_AddTimer(100, snakeSuperModeCall, NULL);

    /* Debug�M�ΡA�Ω��[��C�����A */
    SDL_AddTimer(1000, debugCall, NULL);

    /* ���檽��C������ */
    while(!isDone){
        /* �O���C���B��ɪ��ɶ� */
        Uint32 begTime = SDL_GetTicks();

        /* �ŧi�ƥ��ܼ� */
        SDL_Event ev;

        /* �D�� */
        if(home == true){
            homePage(render);
        }

        /* �C�����e */
        if(pause == false){
            draw(render);
        }

        if(gameOver == true){
            drawLosePage(render);
        }

        /* �B�z�ƥ�A����ثe�L���n�B�̪��ƥ󬰤� */
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_QUIT:
                    isDone = true;  //������Q���U�A�����C��
                    keepScore();
                    break;
                case SDL_KEYDOWN:
                    keyDownEvent(&ev.key); //��L����Q���U�A�bkeyDownEvent()����@�B�B�z
                    break;
            }
        }

        /* �p��{���B����ٳѦh�֮ɶ��A�ϥ�Delay�T�w�V�� */
        Uint32 elapsed = SDL_GetTicks() - begTime;
        int delay = 1000 / FPS - elapsed;

        /* Debug�M�ΡA�Ω��[��delay */
        SDL_Log("%d", delay);

        if(delay > 0) SDL_Delay(delay);
    }
    /* �R��window�Brender�A����IMG�BSDL */
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
