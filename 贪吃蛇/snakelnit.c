#include"snake.h"
score = 0;        //��Ϸ�÷ֳ�ʼ��Ϊ0 
 //���ܣ���ʼ��̰���ߣ�����̰���ߵĳ��ȡ��÷֡�����ʱ������
  void initSnake()
  {
     system("color E");
     SNAKE * body = NULL;
     int i;
     len = 3;         //̰���߳���Ϊ3
     delay = 100;        //ʱ����Ϊ100ms 
     body = (SNAKE*)malloc(sizeof(SNAKE));//̰���������������� 
     body->x = 24;
     body->y = 5;
     body->next = NULL;
      for (i = 1; i <= len; i++)    //����̰���߳�ʼ�����ȴ�С�ڵ� 
      {
          head = (SNAKE*)malloc(sizeof(SNAKE));
          head->next = body;
          head->x = 24 + 2 * i;
          head->y = 5;
          body = head;
      }
      while (body != NULL) //���ն���ʾ̰���� 
      {
         posShow(body->x, body->y);
         printf("��");
         body = body->next;
      }
 }