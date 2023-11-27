#include"snake.h"
extern int score;

//功能：游戏结束后保存玩家信息

void saveInfo()
{
     char playerName[64];
     int i, j;
     FILE * fp;
	 fp = fopen("玩家信息.txt","a+");
     _getch();
	system("cls");
	fprintf(fp, "\n");
	  for (i = 0; i <= 30; i++)
		  fprintf(fp, "%c", '_');
	 fprintf(fp, "\n");
     printf("输入你的姓名:");
     fflush(stdin);
     scanf("%s", playerName);
     fprintf(fp, "玩家姓名 :%s\n", playerName);   //写入玩家信息 
     time_t myTime;
     myTime = time(NULL);
    fprintf(fp, "游戏时间:%s", ctime(&myTime));  //写入时间信息 
    fprintf(fp, "得分:%d\n", score);
    for (i = 0; i <= 30; i++)
	           fprintf(fp, "%c", '_');
     fprintf(fp, "\n");
     fclose(fp);
}

//功能：查看玩家信息

int checkInfo()
{
      char c;
	  FILE * fp;
      fp = fopen("玩家信息,txt","r");
	  if (fp == NULL)
	       return -1;
      else
	  {
            do
		    {
	           putchar(c = getc(fp));
            } while (c != EOF);
	        fclose(fp);
            return 1;
      }
}