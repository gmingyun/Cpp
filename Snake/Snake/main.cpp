#include"snake.h"
int main()
{
	//����һ��ͼ�δ���
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
	//1��2��3Ϊ˫�����ͼ��ֹ��������
	//�ر�ͼ�δ���
	closegraph();
	return 0;
}
