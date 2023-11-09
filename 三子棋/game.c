#define _CRT_SECURE_NO_WARNINGS
#include"game.h"//不要误以为是#define了


//test.c测试游戏的逻辑
//game.c游戏代码的实现
//game.h游戏代码的声明




void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//注意这要空格
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割信息
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{	
	int x = 0, y = 0;
	printf("玩家请输入:>");
	printf("attition:第一个为行，然后空格，第二个为列输入\n");
	//坐标范围合法的判断
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，要点脸吧\n");
			}
		}
		else
		{
			printf("坐标非法，玩呢\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("下棋中...\n");
	int x = 0, y = 0;

	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


//如果满了返回1 反之为0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0,j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}





char IsWin(char board[ROW][COL], int row, int col)
{	//行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][1]!=' ')
		{
			return board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//没有人赢，棋盘满了，就得平局
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}