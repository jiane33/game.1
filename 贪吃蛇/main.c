#include"snake.h"
int main()
{
	//颜色
	system("color 9C");
	int ch;
	system("cls");                             //清空屏幕 
	while (1)
	{
		system("mode con cols=100 lines=30");//设置控制台窗口宽度100，高度为30 
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
			if (checkInfo() == -1) //没有游戏记录，打开文件失败 
			{
				system("cls");
				posShow(40, 6);
				printf("无记录,请返回主菜单开始游戏！");
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
			printf("\a");    //输入不是1、2、3发出警告。 
			fflush(stdout);   //清空输出缓冲区
	}
	     
		}
	getchar();
	return 0;
}





/*
涉及知识点：
函数，链表，指针，动态规划？
涉及库：
windows->system cls color
conio->getch KV
time->srand rand()%
*/