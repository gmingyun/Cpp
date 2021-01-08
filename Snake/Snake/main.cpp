#include"snake.h"
int main()
{
	//创建一个图形窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	GameInit();
	BeginBatchDraw();//1
	while (1)
	{
		if (Timer(10))
		{
			SnakeMove();
		}
		GameDraw();
		FlushBatchDraw();//2
		EatFood();
		KeyControl();
		stop();
	}
	EndBatchDraw();//3    
	//1、2、3为双缓冲绘图防止闪屏代码
	//关闭图形窗口
	closegraph();
	return 0;
}
