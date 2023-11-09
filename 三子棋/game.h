#pragma once

#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define ROW 3
#define COL 3
//定义行和列可以不局限于三子棋盘

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//玩家赢了* 或 电脑赢# 或 平局Q 或 继续C
char IsWin(char board[ROW][COL],int row,int col);