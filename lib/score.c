#include "score.h"

/* �x�s���Z */
void keepScore(){
    /* ���o��� */
    time_t gameOverTime;
    time(&gameOverTime);

    /* �g�J���ƻP�ɶ� */
    FILE *record;
    record = fopen("score.txt", "a");
    if(record == NULL) {
        SDL_Log("Cannot open file.");
        return -1;
    }
    fprintf(record, "score: %d date: %ld\n", score, gameOverTime);
    score = 0;
    fclose(record);
}

/* �ƧǨ禡�A�Ω�qsort() */
int compare(const void *a, const void *b) {
    Record *recordA = (Record *)a;
    Record *recordB = (Record *)b;
    return recordB->score - recordA->score;
}

/* �C�X�Ʀ�](�e�T���̨Φ��Z) */
void ranking(SDL_Renderer *render){
    /* ø�s�Ʀ�]�I��(�¦�) */
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    /* �Nø�s�����e��Wwindow */
    SDL_RenderPresent(render);

    /* �ŧi�ƥ��ܼ� */
    SDL_Event ev;

    /* ���}�r���ɮ� */
    TTF_Font* ttfFont = TTF_OpenFont("font/terminal.ttf", RANKING_FONT_SIZE);
    if(ttfFont == NULL){
        SDL_Log("Cannot open ttf file.");
    }

    /* Ū�L�h�����ƨ��x�s */
    FILE *file = fopen("score.txt", "r");
    if (file == NULL) {
        SDL_Log("Cannot open file.");
        return -1;
    }
    Record records[MAX_RECORDS];    //�ŧi�x�s�������}�C
    int i = 0;
    while(fscanf(file, "score: %d date: %ld\n", &records[i].score, &records[i].date) != EOF && i < MAX_RECORDS){
        i++;
    }
    fclose(file);

    /* �̤��ƥѰ���C�Ƨ� */
    int size = i;
    qsort(records, size, sizeof(Record), compare);
    SDL_Color color = {255, 255, 255, 255}; //�]�w�Ʀ�]�r���C��

    /* RANKING�������D�δ��� */
    SDL_Surface *surface;
    SDL_Texture *texture;
    surface = TTF_RenderUTF8_Blended(ttfFont, "RANKING", color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_Rect blendedRectTopic = {SCREEN_WIDTH / 2 - surface->w / 2, RANKING_FONT_SIZE, surface->w, surface->h};
    SDL_RenderCopy(render, texture, NULL, &blendedRectTopic);
    surface = TTF_RenderUTF8_Blended(ttfFont, "(PRESS H TO GO BACK)", color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_Rect blendedRectTip = {SCREEN_WIDTH / 2 - surface->w / 2, RANKING_FONT_SIZE * 2, surface->w, surface->h};
    SDL_RenderCopy(render, texture, NULL, &blendedRectTip);
    SDL_RenderPresent(render);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    /* ��ܱƦ�] */
    char line[MAX_OUTPUT] = " ";
    for(int i = 0; i < 3 && i < size; i++){
        /* �ഫ�榡 */
        time_t rawtime = (time_t)records[i].date;   //Ū������������ɶ�
        struct tm *timeinfo = localtime(&rawtime);  //�Ntime_t�榡�ഫ��tm���c��
        char date[11];  //�Ω��x�s�~-��-��榡���ɶ�
        strftime(date, sizeof(date), "%Y-%m-%d", timeinfo); //�Ntm�榡�ഫ���~-��-��榡
        sprintf(line, "No.%d Score: %d date: %s", i + 1, records[i].score, date); //�N���Z�ήɶ��s�Jlineline[MAX_OUTPUT]

        /* �N�e�T�W���Z��Wwindow */
        surface = TTF_RenderUTF8_Blended(ttfFont, line, color);
        texture = SDL_CreateTextureFromSurface(render, surface);
        SDL_Rect blendedRect = {SCREEN_WIDTH / 2 - surface->w / 2, RANKING_FONT_SIZE * 3 + i * RANKING_FONT_SIZE, surface->w, surface->h};
        SDL_RenderCopy(render, texture, NULL, &blendedRect);
        SDL_RenderPresent(render);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    /* �����r���ɮ� */
    TTF_CloseFont(ttfFont);

    /* �B�z�ƥ� */
    while((home == false) && (isDone == false)){
        SDL_PollEvent(&ev);
        switch(ev.type){
            case SDL_KEYDOWN:
                if(ev.key.keysym.sym == SDLK_h){
                    /* Enter��Q���U�A�i�J�C�� */
                    home = true;
                }
                break;
            case SDL_QUIT:
                    isDone = true; //������Q���U�A�����C��
                    break;
        }
    }
}

/* ��ܦ��Z */
void printScore(SDL_Renderer *render){
    /* ���}�r���ɮ� */
    TTF_Font* ttfFont = TTF_OpenFont("font/terminal.ttf", RANKING_FONT_SIZE);
    if(ttfFont == NULL){
        SDL_Log("Cannot open ttf file.");
    }

    /* ���Z��ܪ��C��B��m */
    SDL_Color color = {0, 0, 0, 255};
    char Score[10000];
    sprintf(Score, "Score: %d", score);
    SDL_Surface *surface = TTF_RenderUTF8_Blended(ttfFont, Score, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_Rect blendedRect = {SCREEN_WIDTH / 2 - surface->w / 2, 0, surface->w, surface->h};
    SDL_RenderCopy(render, texture, NULL, &blendedRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
