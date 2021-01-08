#ifndef _SNAKE_H_
#define _SNAKE_H_
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#define WIN_WIDTH 640 //���ڿ��
#define WIN_HEIGHT 480
#define MAX_SNAKE 10000 //�ߵ�������
enum DIR //�ߵķ���
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//ÿһ���ߵ�λ����Ϣ
typedef struct _Pos
{
	int x;
	int y;
	DWORD color;
}Pos;
typedef struct Snake_tlg //�ߵĽṹ��
{
	int num;
	int dir;//�ߵķ���
	int score;//����
	int size;//�ߵĿ�Ⱥ͸߶�
	int speed;//�ƶ��ٶ�
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
//���۾�����
void DrawEye(int x, int y);
//��ʼ������
void GameInit();
//��Ϸ�Ļ���
void GameDraw();
//�ߵ��ƶ�
void SnakeMove();
//���Ʒ���
void KeyControl();
// ʳ��
void EatFood();
//��ͣ��Ϸ ���ո���ͣ�ͼ���
void stop();
//��ʱ��
bool Timer(clock_t ms);
#endif
