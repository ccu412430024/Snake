#ifndef score_h
#define score_h

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "setting.h"
#include "status.h"

/* �w�q���Z�������c�� */
typedef struct {
    int score;
    long date;
} Record;

extern Record records[MAX_RECORDS];

/* �x�s���Z */
void keepScore();

/* �ƧǨ禡�A�Ω�qsort() */
int compare(const void *a, const void *b);

/* �C�X�Ʀ�](�e�T���̨Φ��Z) */
void ranking(SDL_Renderer *render);

/* ��ܦ��Z */
void printScore(SDL_Renderer *render);

#endif
