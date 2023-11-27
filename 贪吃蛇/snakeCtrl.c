#include"snake.h"

//功能：控制贪吃蛇移动方向、计算贪吃蛇长度变化及游戏得分
void  snakeMove()
{
	SNAKE * nextPos = NULL; //定义一个SNAKE结构指针 
	nextPos = (SNAKE*)malloc(sizeof(SNAKE));
	if (direct == UP)
	{
	 nextPos->x = head->x;            //横坐标不变 
	 nextPos->y = head->y - 1;         //纵坐标减1 （向上） 
		//吃到食物后，蛇的长度增加 
        if (nextPos->x == food->x && nextPos->y == food->y)
        {
				nextPos->next = head;
		        head = nextPos;
				pHead = head;
		     while (pHead != NULL)       //显示贪吃蛇增长后的长度 
		     {
		         posShow(pHead->x, pHead->y);
		         printf("■");
	             pHead = pHead->next;
			 }
               score = score + factor;   //计算得分 
	           createFood();             //重新产生食物 
	    }
		else //如果没有吃到食物 
		{
	         nextPos->next = head;
		     head = nextPos;
	         pHead = head;
	         while (pHead->next->next != NULL)
             {
	            posShow(pHead->x, pHead->y);
			    printf("■");
		        pHead = pHead->next;
		     }
		 posShow(pHead->next->x, pHead->next->y);
		 printf(" ");
		 free(pHead->next); //释放贪吃蛇节点 
		 pHead->next = NULL;
	    }
    }
     if (direct == DOWN)
	 {
		 nextPos->x = head->x;
		 nextPos->y = head->y + 1;
	     if (nextPos->x == food->x && nextPos->y == food->y)
		 {
		              nextPos->next = head;
			          head = nextPos;
		              pHead = head;
			          while (pHead != NULL)
		              {
			             posShow(pHead->x, pHead->y);
			             printf("■");
			             pHead = pHead->next;
			          }
		             score = score + factor;
	                 createFood();
		 }
	     else
	     {
			 nextPos->next = head;
			head = nextPos;
			pHead = head;
			while (pHead->next->next != NULL)
	        {
				posShow(pHead->x, pHead->y);
			    printf("■");
		        pHead = pHead->next;
			}
			  posShow(pHead->next->x, pHead->next->y);
		      printf(" ");
			  free(pHead->next);
		      pHead->next = NULL;
		 }
	 }
	 if (direct == LEFT)
	 {
		nextPos->x=head-> x - 2;
		 nextPos->y = head->y;
		 if (nextPos->x == food->x && nextPos->y == food->y)//遇到食物了
		 {
			nextPos->next = head;
			head = nextPos;
			 pHead = head;			
			while (pHead != NULL)
			{
				posShow(pHead->x, pHead->y);
				 printf("■");
				  pHead = pHead->next;
			}
			score = score + factor;
			 createFood();//重新生成食物
		 }
		 else
		 {
			nextPos->next = head;
			head = nextPos;
			pHead = head;
			while (pHead->next->next != NULL)
			{
				     posShow(pHead->x, pHead->y);
				     printf("■");
				    pHead = pHead->next;
			}
			posShow(pHead->next->x, pHead->next->y);
		    printf(" ");
			free(pHead->next);
			pHead->next = NULL;
		 }
	 }
	 if (direct == RIGHT)
	 {
		  nextPos->x = head->x + 2;
		  nextPos->y = head->y;
		  if (nextPos->x == food->x && nextPos->y == food->y)
		  {
		     nextPos->next = head;
			  head = nextPos;
			  pHead = head;
			  while (pHead != NULL)
			  {
				  posShow(pHead->x, pHead->y);
				  printf("■");
				  pHead = pHead->next;
			  }
			    score = score + factor;
			     createFood();//重新生成食物
		  }
		  else
		  {
				nextPos->next = head;
				head = nextPos;
				pHead = head;
			  while (pHead->next->next != NULL)
				{
				    posShow(pHead->x, pHead->y);
				    printf("■");
				    pHead = pHead->next;
				 }
			  posShow(pHead->next->x, pHead->next->y);
		      printf(" ");
			  free(pHead->next);
			 pHead->next = NULL;
		  }
	 }
	 posShow(66, 3);
	 printf("得分：%d\n",score);
}

//功能：制定贪吃蛇移动规则
void moveRules() 
{
      direct = RIGHT; //控制游戏  
	   while (1)
	   {
		   //按下向上方向键，且贪吃蛇移动不与向上按键反向 
			if (GetAsyncKeyState(VK_UP) && direct != DOWN)
			direct = UP;//上
			else if (GetAsyncKeyState(VK_DOWN) && direct != UP)
			direct = DOWN;//下
			 else if (GetAsyncKeyState(VK_LEFT) && direct != RIGHT)
			direct = LEFT;//左
			else if (GetAsyncKeyState(VK_RIGHT) && direct != LEFT)
			   direct = RIGHT;//右
			else if (GetAsyncKeyState(VK_SPACE))
			 pause();//空格		暂停
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
			  system("cls");//清屏
			  exit(0);//正常退出
			}
			else if (GetAsyncKeyState(VK_CONTROL))
			{
				  if (delay >= 50)
				  {
						delay = delay - 30;
						factor = factor + 2;
						if (delay == 320)
						    factor = 2;
				  }
			}
			else if (GetAsyncKeyState(VK_SHIFT))
			{
				if (delay < 350)
				{
					delay = delay + 30;
					factor = factor - 2;
					  if (delay == 350)
						  factor = 1;
				}
			}
			Sleep(delay);
			//游戏规则判断 
			crossWall();
			biteSelf();
			snakeMove();
	   }
}