#include"snake.h"
int main()
{
	//��ɫ
	system("color 9C");
	int ch;
	system("cls");                             //�����Ļ 
	while (1)
	{
		system("mode con cols=100 lines=30");//���ÿ���̨���ڿ��100���߶�Ϊ30 
		gameMenu();
		scanf("%d", &ch);
		fflush(stdin);
		switch (ch)
		{
		case 1:
			system("cls");
			createMap();
			gameTips();
			initSnake();
			createFood();
			moveRules();
			break;
		case 2:
			system("cls");
			if (checkInfo() == -1) //û����Ϸ��¼�����ļ�ʧ�� 
			{
				system("cls");
				posShow(40, 6);
				printf("�޼�¼,�뷵�����˵���ʼ��Ϸ��");
				Sleep(300);
				continue;
			}
			else
			{
				system("cls");
				checkInfo();
				scanf("%c", &ch);
				if (_kbhit() == GetAsyncKeyState(VK_ESCAPE))
				
					continue;
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\a");    //���벻��1��2��3�������档 
			fflush(stdout);   //������������
	}
	     
		}
	getchar();
	return 0;
}





/*
�漰֪ʶ�㣺
����������ָ�룬��̬�滮��
�漰�⣺
windows->system cls color
conio->getch KV
time->srand rand()%
*/