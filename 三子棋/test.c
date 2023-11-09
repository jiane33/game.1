#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("*******************\n");
	printf("**1. play 0. exit **\n");
	printf("*******************\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("你赢了\n");
	}
	else if (ret == '#')
	{
		printf("垃圾，这都能输！\n");
	}
	else
	{
		printf("平局:-(\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋,启动!\n");
			game();
			break;
		case 0:
			printf("爱玩不玩\n");
			break;
		default:
			printf("滚去玩原神\n");
			break;
		}
	} while (input);
	return 0;
} 