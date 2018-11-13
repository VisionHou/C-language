#include<windows.h>
#include"game.h"

menu()
{
	printf("###############################\n");
	printf("#######欢迎来到三子棋游戏######\n");
	printf("####### 1.play    0.exit ######\n");
	printf("###############################\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	char win = 0;
	InitBoard(board, ROW, COL);//初始化空格棋盘

	//打印棋盘
	PrintBoard(board, ROW, COL);
	do
	{
		PlayerMove(board, ROW, COL);//玩家走
		PrintBoard(board, ROW, COL);
		win = CheckWin(board, ROW, COL);//检测输赢;玩家赢P 电脑赢0  继续游戏 平局E 
		if (win != ' ')
			break;

		ComputerMove(board, ROW, COL);//电脑走
		PrintBoard(board, ROW, COL);
		win = CheckWin(board, ROW, COL);
		if (win != ' ')
		{
			break;
			PrintBoard(board, ROW, COL);
		}
	}

	while (1);
	if (win == 'P')
		printf("恭喜你你赢了\n");

	else if (win == '0')
		printf("不好意思电脑赢了\n");

	else if (win == 'E')
		printf("平局\n");
}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do {
		menu();//打印菜单
		printf("请选择;>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

}


int main()

{
	test();
	system("pause");
	return 0;
}
