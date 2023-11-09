#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("**************\n");
	printf("*****1.play****\n");
	printf("*****0.exit****\n");
	printf("**************\n");
}

void game()
{
	//虽然是9*9表格，但是为了方便后面的判断周围八个格子有几个雷而多出两行的虚拟表格
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出雷的信息
	//mine数组在没有布置雷为'0'
	//show数组在没有排查雷的时候都是'*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	SetMine(mine, ROW, COL);//设置雷
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine,show,ROW,COL);

}

int main()
{
	int input = 0;
	//设置随机数的生成
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("扫雷，启动！\n");
			game();
			break;
		case 0:
			printf("退出ing~\n");
			break;
		default:
			printf("有大病？\n");
			break;
		}
	}while (input);
	return 0;
}