#include"snake.h"

//���ܣ�����̰�����ƶ����򡢼���̰���߳��ȱ仯����Ϸ�÷�
void  snakeMove()
{
	SNAKE * nextPos = NULL; //����һ��SNAKE�ṹָ�� 
	nextPos = (SNAKE*)malloc(sizeof(SNAKE));
	if (direct == UP)
	{
	 nextPos->x = head->x;            //�����겻�� 
	 nextPos->y = head->y - 1;         //�������1 �����ϣ� 
		//�Ե�ʳ����ߵĳ������� 
        if (nextPos->x == food->x && nextPos->y == food->y)
        {
				nextPos->next = head;
		        head = nextPos;
				pHead = head;
		     while (pHead != NULL)       //��ʾ̰����������ĳ��� 
		     {
		         posShow(pHead->x, pHead->y);
		         printf("��");
	             pHead = pHead->next;
			 }
               score = score + factor;   //����÷� 
	           createFood();             //���²���ʳ�� 
	    }
		else //���û�гԵ�ʳ�� 
		{
	         nextPos->next = head;
		     head = nextPos;
	         pHead = head;
	         while (pHead->next->next != NULL)
             {
	            posShow(pHead->x, pHead->y);
			    printf("��");
		        pHead = pHead->next;
		     }
		 posShow(pHead->next->x, pHead->next->y);
		 printf(" ");
		 free(pHead->next); //�ͷ�̰���߽ڵ� 
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
			             printf("��");
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
			    printf("��");
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
		 if (nextPos->x == food->x && nextPos->y == food->y)//����ʳ����
		 {
			nextPos->next = head;
			head = nextPos;
			 pHead = head;			
			while (pHead != NULL)
			{
				posShow(pHead->x, pHead->y);
				 printf("��");
				  pHead = pHead->next;
			}
			score = score + factor;
			 createFood();//��������ʳ��
		 }
		 else
		 {
			nextPos->next = head;
			head = nextPos;
			pHead = head;
			while (pHead->next->next != NULL)
			{
				     posShow(pHead->x, pHead->y);
				     printf("��");
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
				  printf("��");
				  pHead = pHead->next;
			  }
			    score = score + factor;
			     createFood();//��������ʳ��
		  }
		  else
		  {
				nextPos->next = head;
				head = nextPos;
				pHead = head;
			  while (pHead->next->next != NULL)
				{
				    posShow(pHead->x, pHead->y);
				    printf("��");
				    pHead = pHead->next;
				 }
			  posShow(pHead->next->x, pHead->next->y);
		      printf(" ");
			  free(pHead->next);
			 pHead->next = NULL;
		  }
	 }
	 posShow(66, 3);
	 printf("�÷֣�%d\n",score);
}

//���ܣ��ƶ�̰�����ƶ�����
void moveRules() 
{
      direct = RIGHT; //������Ϸ  
	   while (1)
	   {
		   //�������Ϸ��������̰�����ƶ��������ϰ������� 
			if (GetAsyncKeyState(VK_UP) && direct != DOWN)
			direct = UP;//��
			else if (GetAsyncKeyState(VK_DOWN) && direct != UP)
			direct = DOWN;//��
			 else if (GetAsyncKeyState(VK_LEFT) && direct != RIGHT)
			direct = LEFT;//��
			else if (GetAsyncKeyState(VK_RIGHT) && direct != LEFT)
			   direct = RIGHT;//��
			else if (GetAsyncKeyState(VK_SPACE))
			 pause();//�ո�		��ͣ
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
			  system("cls");//����
			  exit(0);//�����˳�
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
			//��Ϸ�����ж� 
			crossWall();
			biteSelf();
			snakeMove();
	   }
}