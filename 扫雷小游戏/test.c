#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("**************\n");
	printf("*****1.play****\n");
	printf("*****0.exit****\n");
	printf("**************\n");
}

void game()
{
	//��Ȼ��9*9��񣬵���Ϊ�˷��������ж���Χ�˸������м����׶�������е�������
	char mine[ROWS][COLS] = {0};//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų���׵���Ϣ
	//mine������û�в�����Ϊ'0'
	//show������û���Ų��׵�ʱ����'*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	SetMine(mine, ROW, COL);//������
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine,show,ROW,COL);

}

int main()
{
	int input = 0;
	//���������������
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("ɨ�ף�������\n");
			game();
			break;
		case 0:
			printf("�˳�ing~\n");
			break;
		default:
			printf("�д󲡣�\n");
			break;
		}
	}while (input);
	return 0;
}