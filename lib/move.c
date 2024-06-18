#include "move.h"

/* Timer�N�CSNAKE_MOVE_INTERVAL�@����榹��� */
Uint32 *snakeMoveCall(Uint32 interval, SDL_Renderer *render){
    if((pause == false) && (gameOver == false)){
        moveSnake();
        eatGameProps();
        eatFood();
        gameOverConditions(render);
    }
        return speed;
}

/* �B�z�D�Y�γD������m�A�w�ɾ��N�z�LsnakeMoveCall�A�CSNAKE_MOVE_INTERVAL�@����榹��� */
void moveSnake(){
    /* ���`�D����m�Y���e�@�`�D����m */
    for(int i = snake.length - 1; i > 0; i--){
        snake.pos[i] = snake.pos[i - 1];
    }
    /*�ھڥثe�D�Y��V�M�w���ʤ�V*/
    switch(snake.dir){
        case SDLK_UP:
            snake.pos[0].y -= snake.size; //�D�Y�V�W
            if(superMode == true && snake.pos[0].y < 0){
                snake.pos[0].y = SCREEN_HEIGHT - snake.size;
            }
            break;
        case SDLK_DOWN:
            snake.pos[0].y += snake.size; //�D�Y�V�U
            if(superMode == true && snake.pos[0].y >= SCREEN_HEIGHT){
                snake.pos[0].y = 0;
            }
            break;
        case SDLK_LEFT:
            snake.pos[0].x -= snake.size; //�D�Y�V��
            if(superMode == true && snake.pos[0].x < 0){
                snake.pos[0].x = SCREEN_WIDTH - snake.size;
            }
            break;
        case SDLK_RIGHT:
            snake.pos[0].x += snake.size; //�D�Y�V�k
            if(superMode == true && snake.pos[0].x >= SCREEN_WIDTH){
                snake.pos[0].x = 0;
            }
            break;
    }
}

/* �P�_��ث���Q���U */
void keyDownEvent(SDL_KeyboardEvent *ev){
    switch(ev->keysym.sym){
        case SDLK_UP: case SDLK_w:
            snake.dir = SDLK_UP;    //��V��W��W��A�D�Y�V�W
            break;
        case SDLK_DOWN: case SDLK_s:
            snake.dir = SDLK_DOWN;  //��V��U��S��A�D�Y�V�U
            break;
        case SDLK_LEFT: case SDLK_a:
            snake.dir = SDLK_LEFT;  //��V�䥪��A��A�D�Y�V��
            break;
        case SDLK_RIGHT: case SDLK_d:
            snake.dir = SDLK_RIGHT; //��V��k��D��A�D�Y�V�k
            break;
        case SDLK_SPACE:    //�ť���Ȱ��C��
            pause = !pause;
            break;
    }
}
