#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

//宏定义
#define UP 76
#define DOWN 52
#define LEFT 78
#define RIGHT 43

//定义结构体
typedef struct snake
{
	int x;
	int y;
	struct snake* next;
}SNAKE;

//其他变量定义
int len;//贪吃蛇长度
int factor; //食物分值
int direct; //贪吃蛇运动方向
int delay;//运动的时间间隔
SNAKE* head;//蛇头指针
SNAKE* food;//食物指针
SNAKE* pHead;//遍历蛇的时候用到的指针
int score;//分数
//函数声明
 void posShow();
 void createMap();
 void initSnake();
 int biteSelf();
 void createFood();
 void crossWall();
 void snakeMove();
 void pause();
 void moveRules();
 void snakeReborn();
 void saveInfo();
 int checkInfo();
 void gameTips();
