#include<windows.h>
#include"game.h"

menu()
{
	printf("###############################\n");
	printf("#######��ӭ������������Ϸ######\n");
	printf("####### 1.play    0.exit ######\n");
	printf("###############################\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	char win = 0;
	InitBoard(board, ROW, COL);//��ʼ���ո�����

	//��ӡ����
	PrintBoard(board, ROW, COL);
	do
	{
		PlayerMove(board, ROW, COL);//�����
		PrintBoard(board, ROW, COL);
		win = CheckWin(board, ROW, COL);//�����Ӯ;���ӮP ����Ӯ0  ������Ϸ ƽ��E 
		if (win != ' ')
			break;

		ComputerMove(board, ROW, COL);//������
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
		printf("��ϲ����Ӯ��\n");

	else if (win == '0')
		printf("������˼����Ӯ��\n");

	else if (win == 'E')
		printf("ƽ��\n");
}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do {
		menu();//��ӡ�˵�
		printf("��ѡ��;>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
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
