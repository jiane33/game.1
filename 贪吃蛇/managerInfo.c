#include"snake.h"
extern int score;

//���ܣ���Ϸ�����󱣴������Ϣ

void saveInfo()
{
     char playerName[64];
     int i, j;
     FILE * fp;
	 fp = fopen("�����Ϣ.txt","a+");
     _getch();
	system("cls");
	fprintf(fp, "\n");
	  for (i = 0; i <= 30; i++)
		  fprintf(fp, "%c", '_');
	 fprintf(fp, "\n");
     printf("�����������:");
     fflush(stdin);
     scanf("%s", playerName);
     fprintf(fp, "������� :%s\n", playerName);   //д�������Ϣ 
     time_t myTime;
     myTime = time(NULL);
    fprintf(fp, "��Ϸʱ��:%s", ctime(&myTime));  //д��ʱ����Ϣ 
    fprintf(fp, "�÷�:%d\n", score);
    for (i = 0; i <= 30; i++)
	           fprintf(fp, "%c", '_');
     fprintf(fp, "\n");
     fclose(fp);
}

//���ܣ��鿴�����Ϣ

int checkInfo()
{
      char c;
	  FILE * fp;
      fp = fopen("�����Ϣ,txt","r");
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