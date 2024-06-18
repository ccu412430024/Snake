#ifndef score_h
#define score_h

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "setting.h"
#include "status.h"

/* 定義成績紀錄結構體 */
typedef struct {
    int score;
    long date;
} Record;

extern Record records[MAX_RECORDS];

/* 儲存成績 */
void keepScore();

/* 排序函式，用於qsort() */
int compare(const void *a, const void *b);

/* 列出排行榜(前三次最佳成績) */
void ranking(SDL_Renderer *render);

/* 顯示成績 */
void printScore(SDL_Renderer *render);

#endif
