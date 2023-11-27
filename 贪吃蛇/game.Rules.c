#include"snake.h"
int life = 3;//三条命
int flag = 0;//用于函数返回值，判断贪吃蛇状态 
extern int score;

//功能：判断贪吃蛇是否撞墙
 void crossWall()
 {
      //游戏窗口建立时的大小作为活动范围 
     if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
     {
         flag = 1;
         life--;//扣一条命
         snakeReborn();//蛇重新生成
	 }
}

//功能：判断蛇是否咬到了自己
 int biteSelf()
 {
    SNAKE * self;
	self = head->next;
	int flag;
	 while (self != NULL)
	 {   //遍历链表，判断是否有蛇身节点与蛇头节点重合
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

//功能：重新生成一条贪吃蛇
void snakeReborn()
{
    char ch, key = 0;
    //贪吃蛇死了情况
   if (life == 0)
   {
        system("cls");
        posShow(24, 13);
        printf("贪吃蛇死亡。得分：%d\n", score);
	    Sleep(2000);
        system("cls");
		saveInfo();
		posShow(7, 7);
		printf("游戏退出");
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

//功能：第1次按下空格键时暂停游戏，第2次按下继续游戏
void pause()
{
   while (1)
   {
     Sleep(300);//0.3s
     if (GetAsyncKeyState(VK_SPACE)) //按键是空格键 
           break;//第二次按空格键代表跳出循环继续游戏
   }
}