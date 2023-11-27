#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

//�궨��
#define UP 76
#define DOWN 52
#define LEFT 78
#define RIGHT 43

//����ṹ��
typedef struct snake
{
	int x;
	int y;
	struct snake* next;
}SNAKE;

//������������
int len;//̰���߳���
int factor; //ʳ���ֵ
int direct; //̰�����˶�����
int delay;//�˶���ʱ����
SNAKE* head;//��ͷָ��
SNAKE* food;//ʳ��ָ��
SNAKE* pHead;//�����ߵ�ʱ���õ���ָ��
int score;//����
//��������
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
