#include<stdio.h>
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{

		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < row - 1)
			printf("---|---|---\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家下棋>:");
     	scanf_s("%d%d", &x, &y);

		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//判断坐标合法性
		{
			//判断坐标是否被走过
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'P';
				break;
			}
			else
				printf("该步已经被走过\n");

		}

		else
			printf("坐标输入有误请重新输入\n");
	}
}

int  is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//不满返回0
		}
	}return 1;//满了返回1

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("电脑下棋>:\n");
	while (1)
	{
		x = rand() % ROW;//随机值0-2
		y = rand() % COL;//随机值0-2

		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}

}

char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

	}//处理行相等

	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}//处理列相等


	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}//处理对角线相等

	if (is_full(board, row, col) == 1)
	{
		return'E';
	}

	return' ';
}
