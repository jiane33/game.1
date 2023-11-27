#include"snake.h"
score = 0;        //游戏得分初始化为0 
 //功能：初始化贪吃蛇，包括贪吃蛇的长度、得分、运行时间间隔等
  void initSnake()
  {
     system("color E");
     SNAKE * body = NULL;
     int i;
     len = 3;         //贪吃蛇长度为3
     delay = 100;        //时间间隔为100ms 
     body = (SNAKE*)malloc(sizeof(SNAKE));//贪吃蛇身体由链表构成 
     body->x = 24;
     body->y = 5;
     body->next = NULL;
      for (i = 1; i <= len; i++)    //开辟贪吃蛇初始化长度大小节点 
      {
          head = (SNAKE*)malloc(sizeof(SNAKE));
          head->next = body;
          head->x = 24 + 2 * i;
          head->y = 5;
          body = head;
      }
      while (body != NULL) //在终端显示贪吃蛇 
      {
         posShow(body->x, body->y);
         printf("■");
         body = body->next;
      }
 }