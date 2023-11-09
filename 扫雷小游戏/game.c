#define _CRT_SECURE_NO_WARNINGS
#include"game.h"






void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("-------扫雷游戏-------\n");
	//打印行列
	for (j = 0; j <= col; j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);//打印行列
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("-------扫雷游戏-------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//10个雷
	while (count)
	{	
		//横坐标1-9 纵坐标1-9
		//雷随机生成的坐标
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char board[ROWS][COLS],int x,int y)
{
	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]-8*'0');
}




void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;//找到非雷的个数
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("这坐标被排查过了，好吧\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{	//如果直接被雷炸死了
					printf("YOU ARE DEATH!\n BAD  ENDING\n");
					//给玩家展示其雷的所在地
					DisplayBoard(mine, ROW, COL);
					break;
				}
				// 如果不是雷
				else
				{
					win++;
					//统计mine数组xy坐标周围有几个雷
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
				}
			}		
		}
		else
		{
			printf("输入坐标非法，去你的吧！\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("HAPPY END YOU ARE WINNER\n");
		DisplayBoard(mine, ROW, COL);
	}
}