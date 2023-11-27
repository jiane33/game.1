#include"snake.h"
//功能：贪食蛇食物随机产生
void createFood()
{
      srand((unsigned)time(NULL));//随机生成
      SNAKE * newFood;
      newFood = (SNAKE*)malloc(sizeof(SNAKE));//动态规划
      factor = 5;//一个食物5分
      //保证食物在墙里生成
      do
      {
         newFood->x = rand() % 52 + 2;
         newFood->y = rand() % 24 + 1;
      }while ((newFood->x % 2) != 0);  //产生的x轴坐标点为偶数，目的是每次吃到食物时蛇头与食物相撞精确
     posShow(newFood->x, newFood->y);  //食物位置显示 
     food = newFood;                     //将newFood指针赋值给food 
     printf("■");                        //输出食物 
     pHead = head;
     while (pHead->next == NULL)       //判断贪吃蛇是否吃到食物 
     {
         if (pHead->x == newFood->x && pHead->y == newFood->y)
         {
            delay = delay - 30;
            free(newFood);             //吃到食物后释放食物节点开辟的空间（动态规划记得释放空间） 
              createFood();              //吃到食物后再次产生食物 
         }
          pHead = pHead->next;
     }
}