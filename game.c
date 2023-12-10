#include "game.h"

//初始化函数
void initialization(char initi[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			initi[i][j] = set;
		}

	}

}

//打印棋盘
void Print_chessboard(char print[ROWS][COLS], int row, int col)
{
	printf("--------扫雷游戏-------\n");
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		Sleep(10);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", print[i][j]);
			Sleep(0);
		}
		printf("\n");
	}
	printf("\n");

}

//雷的布置
void Lay_mines(char mine[ROWS][COLS], int row, int col)
{
	int mines = EASY_COUNT;

	while (mines)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			mines--;

		}
	}
}

//扫描周围有多少雷
static int printnime(char nime[ROWS][COLS], int x, int y)
{
	int cot = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			cot += (nime[i][j] - '0');
		}
	}
	return cot;
}

// 计算周围的雷数
static int countMines(char nime[ROWS][COLS], int x, int y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			// 排除当前格子
			if (i == x && j == y)
				continue;

			// 检查边界
			if (i >= 0 && i < ROWS && j >= 0 && j < COLS)
			{
				count += (nime[i][j] == '1');
			}
		}
	}
	return count;
}



//雷的排查
void screening(char show[ROWS][COLS], char nime[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;

	while (win < row * col - EASY_COUNT)
	{
		system("cls");
		Print_chessboard(show, ROW, COL);
		printf("请输入排查的坐标:>\n");
		scanf("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (nime[x][y] == '1')
			{
				printf("抱歉你踩雷了，游戏结束\n");
				Print_chessboard(nime, ROW, COL);
				break;
			}
			else
			{
				int conte = printnime(nime, x, y);
				show[x][y] = conte + '0';
				Print_chessboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标输入错误，请重新输入\n");
		}

	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜排雷成功\n");
		Print_chessboard(nime, ROW, COL);

	}
}


