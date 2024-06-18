#include "score.h"

/* 儲存成績 */
void keepScore(){
    /* 取得日期 */
    time_t gameOverTime;
    time(&gameOverTime);

    /* 寫入分數與時間 */
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

/* 排序函式，用於qsort() */
int compare(const void *a, const void *b) {
    Record *recordA = (Record *)a;
    Record *recordB = (Record *)b;
    return recordB->score - recordA->score;
}

/* 列出排行榜(前三次最佳成績) */
void ranking(SDL_Renderer *render){
    /* 繪製排行榜背景(黑色) */
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    /* 將繪製之內容放上window */
    SDL_RenderPresent(render);

    /* 宣告事件變數 */
    SDL_Event ev;

    /* 打開字體檔案 */
    TTF_Font* ttfFont = TTF_OpenFont("font/terminal.ttf", RANKING_FONT_SIZE);
    if(ttfFont == NULL){
        SDL_Log("Cannot open ttf file.");
    }

    /* 讀過去的分數並儲存 */
    FILE *file = fopen("score.txt", "r");
    if (file == NULL) {
        SDL_Log("Cannot open file.");
        return -1;
    }
    Record records[MAX_RECORDS];    //宣告儲存紀錄的陣列
    int i = 0;
    while(fscanf(file, "score: %d date: %ld\n", &records[i].score, &records[i].date) != EOF && i < MAX_RECORDS){
        i++;
    }
    fclose(file);

    /* 依分數由高到低排序 */
    int size = i;
    qsort(records, size, sizeof(Record), compare);
    SDL_Color color = {255, 255, 255, 255}; //設定排行榜字體顏色

    /* RANKING頁面標題及提示 */
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

    /* 顯示排行榜 */
    char line[MAX_OUTPUT] = " ";
    for(int i = 0; i < 3 && i < size; i++){
        /* 轉換格式 */
        time_t rawtime = (time_t)records[i].date;   //讀取此行紀錄的時間
        struct tm *timeinfo = localtime(&rawtime);  //將time_t格式轉換為tm結構體
        char date[11];  //用於儲存年-月-日格式的時間
        strftime(date, sizeof(date), "%Y-%m-%d", timeinfo); //將tm格式轉換為年-月-日格式
        sprintf(line, "No.%d Score: %d date: %s", i + 1, records[i].score, date); //將成績及時間存入lineline[MAX_OUTPUT]

        /* 將前三名成績放上window */
        surface = TTF_RenderUTF8_Blended(ttfFont, line, color);
        texture = SDL_CreateTextureFromSurface(render, surface);
        SDL_Rect blendedRect = {SCREEN_WIDTH / 2 - surface->w / 2, RANKING_FONT_SIZE * 3 + i * RANKING_FONT_SIZE, surface->w, surface->h};
        SDL_RenderCopy(render, texture, NULL, &blendedRect);
        SDL_RenderPresent(render);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    /* 消滅字體檔案 */
    TTF_CloseFont(ttfFont);

    /* 處理事件 */
    while((home == false) && (isDone == false)){
        SDL_PollEvent(&ev);
        switch(ev.type){
            case SDL_KEYDOWN:
                if(ev.key.keysym.sym == SDLK_h){
                    /* Enter鍵被按下，進入遊戲 */
                    home = true;
                }
                break;
            case SDL_QUIT:
                    isDone = true; //關閉鍵被按下，結束遊戲
                    break;
        }
    }
}

/* 顯示成績 */
void printScore(SDL_Renderer *render){
    /* 打開字體檔案 */
    TTF_Font* ttfFont = TTF_OpenFont("font/terminal.ttf", RANKING_FONT_SIZE);
    if(ttfFont == NULL){
        SDL_Log("Cannot open ttf file.");
    }

    /* 成績顯示的顏色、位置 */
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
