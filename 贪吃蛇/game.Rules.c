#include"snake.h"
int life = 3;//������
int flag = 0;//���ں�������ֵ���ж�̰����״̬ 
extern int score;

//���ܣ��ж�̰�����Ƿ�ײǽ
 void crossWall()
 {
      //��Ϸ���ڽ���ʱ�Ĵ�С��Ϊ���Χ 
     if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
     {
         flag = 1;
         life--;//��һ����
         snakeReborn();//����������
	 }
}

//���ܣ��ж����Ƿ�ҧ�����Լ�
 int biteSelf()
 {
    SNAKE * self;
	self = head->next;
	int flag;
	 while (self != NULL)
	 {   //���������ж��Ƿ�������ڵ�����ͷ�ڵ��غ�
         if (self->x == head->x && self->y == head->y)
         {
             life--;
             flag = 2;
             snakeReborn();
              return flag;
		 }
       self = self->next;
     }
     return 0;
 }

//���ܣ���������һ��̰����
void snakeReborn()
{
    char ch, key = 0;
    //̰�����������
   if (life == 0)
   {
        system("cls");
        posShow(24, 13);
        printf("̰�����������÷֣�%d\n", score);
	    Sleep(2000);
        system("cls");
		saveInfo();
		posShow(7, 7);
		printf("��Ϸ�˳�");
		Sleep(500);
        exit(0);
   }
   if (flag == 1 || flag == 2)
   {
       system("cls");
	   createMap();
       gameTips();
	   initSnake();
	   createFood();
       moveRules();
   }
}

//���ܣ���1�ΰ��¿ո��ʱ��ͣ��Ϸ����2�ΰ��¼�����Ϸ
void pause()
{
   while (1)
   {
     Sleep(300);//0.3s
     if (GetAsyncKeyState(VK_SPACE)) //�����ǿո�� 
           break;//�ڶ��ΰ��ո����������ѭ��������Ϸ
   }
}