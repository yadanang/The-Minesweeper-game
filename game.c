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
		printf("%2d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		Sleep(10);
		for (int j = 1; j <= col; j++)
		{
			printf("%2c ", print[i][j]);
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
	int result = 0;


	
	
	while (win < row * col - EASY_COUNT)
	{
		printf("！！！！！！注意请输入正确！！！！！！\n");
		printf("请输入排查的坐标(如：（3,3）):>\n");
		result = scanf("%d,%d", &x, &y);
		while (getchar() != '\n'); // 清空输入缓冲



			if (show[x][y] == '*' && x <= row && x >= 1 && y <= col && y >= 1 && result == 2)
			{
				system("cls");
				printf("成功读取坐标：%d , %d\n", x, y);
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
				system("cls");
				printf("！！！！！！坐标是否重复输入?\\输入格式有误?请重新输入！！！！！！\n");
				printf("！！！！！！坐标是否重复输入?\\输入格式有误?请重新输入！！！！！！\n");
				printf("！！！！！！坐标是否重复输入?\\输入格式有误?请重新输入！！！！！！\n");
				printf("上一次输入的坐标是：%d , %d\n", x, y);

				Print_chessboard(show, ROW, COL);

			}
		

	} 

		if (win == row * col - EASY_COUNT)
		{
		Print_chessboard(nime, ROW, COL);
		// 游戏结束后输入玩家信息
		printf("恭喜排雷成功，我将把你拉入排行榜\n请输入您的称号 如：(亿万少女的梦)：>  ");
		scanf("%s", playerName);
		seconds = elapsed_time;

		// 更新排行榜
		updateLeaderboard(playerName, seconds);

		// 显示排行榜
		displayLeaderboard();

		printf("\n\n\n");

		}
}




//显示排行榜
void displayLeaderboard() {
	printf("=============================================\n");
	printf("                游戏排行榜                    \n");
	printf("=============================================\n");
	printf("%-4s %-15s %-10s\n", "排名", "玩家名字", "用时（秒）");

	// 读取排行榜文件
	FILE* file = fopen("leaderboard.txt", "r");
	if (file == NULL) 
	{
		perror("打开排行榜文件时出错");
		exit(EXIT_FAILURE);
	}

	Player players[MAX_PLAYERS];

	// 从文件中读取玩家信息
	int i = 0;
	while (fscanf(file, "%s %d", players[i].name, &players[i].seconds) == 2 && i < MAX_PLAYERS) 
	{
		i++;
	}

	fclose(file);

	// 对玩家按时间进行升序排序
	for (int j = 0; j < i - 1; j++) 
	{
		for (int k = j + 1; k < i; k++)
		{
			
			if (players[j].seconds > players[k].seconds)
			{
				Player temp = players[j];
				players[j] = players[k];
				players[k] = temp;
			}
		}
	}

	// 打印排行榜
	for (int j = 0; j < i; j++)
	{
		printf("| %-4d %-15s %-10d\n", j + 1, players[j].name, players[j].seconds);
	}
}

// 更新排行榜
void updateLeaderboard(const char* playerName, double seconds) {
	FILE* file = fopen("leaderboard.txt", "a");
	if (file == NULL) {
		perror("打开排行榜文件时出错");
		exit(EXIT_FAILURE);
	}

	// 写入新玩家信息到文件
	fprintf(file, "%s %u\n", playerName, seconds);

	fclose(file);
}


// 清空排行榜
void clearLeaderboard() {
	FILE* file = fopen("leaderboard.txt", "w");
	if (file == NULL) {
		perror("打开排行榜文件时出错");
		exit(EXIT_FAILURE);
	}

	fclose(file);
}
