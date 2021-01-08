#include"snake.h"
Snake snake;
Food food;
//画眼睛函数
void DrawEye(int x, int y)
{
	setfillcolor(WHITE);
	solidcircle(x, y, 3);
	setfillcolor(BLACK);
	solidcircle(x, y, 2);
}
void GameInit()
{
	srand(GetTickCount());
	//初始化蛇
	snake.num = 10;
	snake.dir = RIGHT;
	snake.score = 0;
	snake.size = 10;
	snake.speed = 1;
	snake.coor[0].x = 20;
	snake.coor[0].y = 10;
	for (int i = 0; i < snake.num; i++)
	{
		snake.coor[i].color = GREEN;
	}
	//初始化食物
	food.x = rand() % (WIN_WIDTH - 10);
	food.y = rand() % (WIN_HEIGHT - 10);
	food.flag = 1;
	food.r = rand() % 3 + 2;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
}
void GameDraw()
{
	//设置背景颜色
	setbkcolor(RGB(191, 215, 215));
	cleardevice();
	//画蛇 
	for (int i = 0; i < snake.num; i++)
	{
		setfillcolor(snake.coor[i].color);
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.size / 2);
	}
	//画眼睛
	int eyewidth = 5;
	switch (snake.dir)
	{
	case UP:
	case DOWN:
		DrawEye(snake.coor[0].x - eyewidth, snake.coor[0].y);
		DrawEye(snake.coor[0].x + eyewidth, snake.coor[0].y);
		break;
	case LEFT:
	case RIGHT:
		DrawEye(snake.coor[0].x, snake.coor[0].y - eyewidth);
		DrawEye(snake.coor[0].x, snake.coor[0].y + eyewidth);
		break;
	}
	//画食物
	if (food.flag == 1)
	{
		setfillcolor(food.color);
		solidcircle(food.x, food.y, food.r);
	}
	//显示分数
	char temp[20] = "";
	sprintf_s(temp, "分数:%d", snake.score);
	setbkmode(TRANSPARENT);
	outtextxy(20, 20, temp);
}
void SnakeMove()
{
	for (int i = snake.num - 1; i > 0; i--)//从最后一节蛇开始，每一节蛇都等于前一节蛇的上一次坐标
	{
		snake.coor[i].x = snake.coor[i - 1].x;
		snake.coor[i].y = snake.coor[i - 1].y;
	}
	//根据方向移动
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y + 10 <= 0)
		{
			snake.coor[0].y = WIN_HEIGHT;
		}
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y - 10 >= WIN_HEIGHT)
		{
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x + 10 <= 0)
		{
			snake.coor[0].x = WIN_WIDTH;
		}
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x - 10 >= WIN_WIDTH)
		{
			snake.coor[0].x = 0;
		}
		break;
	}

}

void KeyControl()
{
	//使用win32API获取键盘消息
	if (GetAsyncKeyState(VK_UP) && snake.dir != DOWN)
	{
		snake.dir = UP;
	}
	if (GetAsyncKeyState(VK_DOWN) && snake.dir != UP)
	{
		snake.dir = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) && snake.dir != RIGHT)
	{
		snake.dir = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) && snake.dir != LEFT)
	{
		snake.dir = RIGHT;
	}
	//按A键加速,不按回复初始状态
	if (GetAsyncKeyState('A') && snake.speed == 1)
	{
		snake.speed = 5;
	}
	else if (snake.speed == 5)
	{
		snake.speed = 1;
	}
}


void EatFood()
{
	if (snake.coor[0].x >= food.x - food.r && snake.coor[0].x <= food.x + food.r &&
		snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r &&
		food.flag == 1)
	{
		snake.num += 5;
		snake.score += 10;
		food.flag = 0;
		//每一节的颜色都要初始化
		for (int i = snake.num - 5; i < snake.num; i++)
		{
			snake.coor[i].color = food.color;
		}
	}
	if (food.flag == 0)
	{
		food.x = rand() % (WIN_WIDTH - 10);
		food.y = rand() % (WIN_HEIGHT - 10);
		food.flag = 1;
		food.r = rand() % 10 + 3;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	}
}

void stop()
{
	if (_kbhit() && _getch() == 32)
	{
		while (_getch() != 32);
	}
}

bool Timer(clock_t ms)
{
	static clock_t t = clock();
	if (clock() - t > ms)
	{
		t = clock();
		return true;
	}
	return false;
}
