#pragma once

#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define ROW 3
#define COL 3
//�����к��п��Բ���������������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);


//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//���Ӯ��* �� ����Ӯ# �� ƽ��Q �� ����C
char IsWin(char board[ROW][COL],int row,int col);