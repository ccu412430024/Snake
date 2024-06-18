#include "pages.h"

/* �D�e�� */
void homePage(SDL_Renderer *render){
    /* �Ȱ��C�� */
    pause = true;

    /* ���J�D�e���Ϥ� */
    drawHomePage(render);

    /* �ŧi�ƥ��ܼ� */
    SDL_Event ev;

    /* �B�z�ƥ� */
    while(home == true && isDone == false){
        SDL_PollEvent(&ev);
        switch(ev.type){
            case SDL_KEYDOWN:
                if(ev.key.keysym.sym == SDLK_RETURN){
                    /* Enter��Q���U�A�i�J�C�� */
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
                isDone = true; //������Q���U�A�����C��
                break;
        }
    }
}

/* �D�e���I�� */
void drawHomePage(SDL_Renderer *render){
    /* ���J�D�e���Ϥ� */
    SDL_Texture *backGround = IMG_LoadTexture(render, "img/snake.jpg");
    SDL_RenderCopy(render, backGround, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_DestroyTexture(backGround);
}


/* �鱼�C���ɪ��e�� */
void drawLosePage(SDL_Renderer *render){
    SDL_Texture *backGround = IMG_LoadTexture(render, "img/lose.png");
    SDL_RenderCopy(render, backGround, NULL, NULL);
    SDL_RenderPresent(render);
    SDL_DestroyTexture(backGround);
}

/* �C��������n�~��Φ^��D�e�� */
void continueOrHomePage(){
    /* �ŧi�ƥ��ܼ� */
    SDL_Event ev;
    /* �B�z�ƥ� */
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
