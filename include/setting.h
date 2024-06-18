#ifndef setting_h
#define setting_h

/**********原版視窗寬度、高度************************
#define SCREEN_WIDTH 640    //遊戲視窗寬度
#define SCREEN_HEIGHT 480   //遊戲視窗高度
*********************************************/
#define SCREEN_WIDTH 960    //遊戲視窗寬度
#define SCREEN_HEIGHT 720   //遊戲視窗高度
#define INIT_LENGTH 3   //蛇的初始長度(節數)
#define MAX_LENGTH 500  //蛇的最大長度
#define MAX_FOOD_AMOUNT 40  //同時顯示在畫面中的最大食物數量
#define FOOD_POINT 2   //每個食物的加分數
/*******原版地圖方格寬度**********
#define GRID_WIDTH 10
**********************************/
#define GRID_WIDTH 20   //放大版地圖方格寬度
#define FPS 60.0  //每秒幀數
#define SNAKE_MOVE_INTERVAL 100 //蛇每次移動的間隔，單位ms
#define MAX_RECORDS 100 //最大紀錄數量
#define MAX_OUTPUT 256  //最大字串長度
#define RANKING_FONT_SIZE 44 //RANKING頁面字體大小
#define MIN_COLOR 0 //食物顏色RGB值最小值
#define MAX_COLOR 255   //食物顏色RGB值最大值
#define MAX_GAME_PROPS_AMOUNT 4 //同時顯示在畫面中的最大道具數量
#define INIT_GAME_PROPS_AMOUNT 1 //初始畫面中的道具數量
#define GAME_PROPS_GRID_AMOUNT 2 //道具寬度，單位為GRID_WIDTH，即格數
#define SUPER_MODE_TIME 5000  //道具持續時間
#define GET_GAME_PROPS_SCORE 100    //每GET_GAME_PROPS_SCORE分獲得一個道具

#endif
