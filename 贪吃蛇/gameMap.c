#include"snake.h"
extern int life;
//����̨����������λ����ʾ��Ϣ
void posShow(int x, int y)
{
	COORD pos;		//�����ṹ��
	HANDLE hOutput; //Windows��������ز�������Դ����
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);	//��ü�������
	SetConsoleCursorPosition(hOutput, pos);		//��ü�������
}

//����̰���߻���ڷ�Χ����Ϸ��Ϣ��ʾλ��
void createMap()
{
	system("color 8");
	int i;
	for (i = 0; i < 58; i += 2)
	{
		posShow(i, 0);
		printf("��");
		posShow(i, 26);
		printf("��");
	}
	for (i = 1; i < 26; i++)
	{
		posShow(0, i);
		printf("��");
		posShow(56,i);
		printf("��");
	}
}

//�ڴ����Ҳ���ʾ��Ϸ˵��
void gameTips()
{
	posShow(65, 2);
	printf("=======================\n");
	posShow(80,3);
	printf("����ֵ:%d\n",life);
	posShow(65, 4);
	printf("=======================\n");
	posShow(75,6);
	printf("	|��Ϸ�淨|\n");
	posShow(65, 8);
	printf("1.ʹ�÷���������ߵ��ƶ���\n");
	posShow(65,10);
	printf("2.CTRL̰���߼���;SHIFT̰���߼��١�");
	posShow(65,12);
	printf("3.ESC�˳���Ϸ;�ո���ͣ��Ϸ��");
	posShow(65,14);
	printf("4.��Ϸ�����������������������Ϣ\n");
}


//������Ϸ��ʼ�˵�
void gameMenu()
{
	posShow(40,3);
	printf("̰������Ϸ");
	posShow(40,6);
	printf("1->start  3->exit");
	posShow(40,7);
	printf("2->��ѯ�����Ϣ Enter���������˵�");
	posShow(40,9);
	printf("ѡ��:");
}
