#include"snake.h"
extern int life;
//控制台窗体中任意位置显示信息
void posShow(int x, int y)
{
	COORD pos;		//坐标点结构体
	HANDLE hOutput; //Windows句柄，返回操作的资源对象
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);	//获得键盘输入
	SetConsoleCursorPosition(hOutput, pos);		//获得键盘输入
}

//定义贪吃蛇活动窗口范围及游戏信息显示位置
void createMap()
{
	system("color 8");
	int i;
	for (i = 0; i < 58; i += 2)
	{
		posShow(i, 0);
		printf("■");
		posShow(i, 26);
		printf("■");
	}
	for (i = 1; i < 26; i++)
	{
		posShow(0, i);
		printf("■");
		posShow(56,i);
		printf("■");
	}
}

//在窗口右侧显示游戏说明
void gameTips()
{
	posShow(65, 2);
	printf("=======================\n");
	posShow(80,3);
	printf("生命值:%d\n",life);
	posShow(65, 4);
	printf("=======================\n");
	posShow(75,6);
	printf("	|游戏玩法|\n");
	posShow(65, 8);
	printf("1.使用方向键控制蛇的移动。\n");
	posShow(65,10);
	printf("2.CTRL贪吃蛇加速;SHIFT贪吃蛇减速。");
	posShow(65,12);
	printf("3.ESC退出游戏;空格暂停游戏。");
	posShow(65,14);
	printf("4.游戏结束后输入姓名保存玩家信息\n");
}


//构建游戏开始菜单
void gameMenu()
{
	posShow(40,3);
	printf("贪吃蛇游戏");
	posShow(40,6);
	printf("1->start  3->exit");
	posShow(40,7);
	printf("2->查询玩家信息 Enter键返回主菜单");
	posShow(40,9);
	printf("选项:");
}
