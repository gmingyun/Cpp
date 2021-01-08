#ifndef _SNAKE_H_
#define _SNAKE_H_
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#define WIN_WIDTH 640 //窗口宽高
#define WIN_HEIGHT 480
#define MAX_SNAKE 10000 //蛇的最大节数
enum DIR //蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//每一节蛇的位置信息
typedef struct _Pos
{
	int x;
	int y;
	DWORD color;
}Pos;
typedef struct Snake_tlg //蛇的结构体
{
	int num;
	int dir;//蛇的方向
	int score;//分数
	int size;//蛇的宽度和高度
	int speed;//移动速度
	Pos coor[MAX_SNAKE];
}Snake;
typedef struct Food_tlg
{
	int x;
	int y;
	int r;
	int flag;
	DWORD color;
}Food;
//画眼睛函数
void DrawEye(int x, int y);
//初始化数据
void GameInit();
//游戏的绘制
void GameDraw();
//蛇的移动
void SnakeMove();
//控制方向
void KeyControl();
// 食物
void EatFood();
//暂停游戏 按空格暂停和继续
void stop();
//定时器
bool Timer(clock_t ms);
#endif
