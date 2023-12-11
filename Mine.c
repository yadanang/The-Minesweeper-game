#include"game.h"

void menu()
{
	printf("=============================================\n");
	printf("                  游戏菜单                    \n");
	printf("=============================================\n");
	printf("1. 开始游戏\n");
	printf("0. 退出游戏\n");
	printf("=============================================\n");
}

void meun2()
{
	printf("                选择游戏模式                    \n");
	printf("=============================================\n");
	printf("1. 初级难度\n");
	printf("2. 中级难度\n");
	printf("3. 高级难度\n");
	printf("4. 自由定义 \n");
	printf("2. 查看排行榜\n");
	printf("3. 设置\n");
	printf("=============================================\n");
}


void game()
{
	char mine[ROWS][COLS];//存放布置好的雷
	char show[ROWS][COLS];//存放排查出的雷的信息

	//初始化函数的实现
	initialization(mine, ROWS, COLS, '0');
	initialization(show, ROWS, COLS, '*');

	//打印棋盘函数实现
	Print_chessboard(show, ROW, COL);
	//Print_chessboard(mine, ROW, COL);


	//布置雷
	Lay_mines(mine, ROW, COL);

	

	//类的排查
	screening(show, mine, ROW, COL);

}

int main()
{
	time_t start, end;
	double elapsed_time;
	int b;
	int input = 0; 
	int input2 = 0;

	srand((unsigned int)time(NULL));


	do
	{
		menu();
		printf("Please select:>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			meun2();
			printf("Please select:>");
			scanf("%d", &input2);
			system("cls");
			switch (input2)
			{
			case 1:
				// 记录闯关前的时间
				start = time(NULL);
				game();//初级
				// 记录闯关后的时间
				end = time(NULL);
				// 计算所用时间（秒）
				elapsed_time = difftime(end, start);

				printf("——————————————\n", elapsed_time);
				printf("|耗时：%.2f 秒|\n", elapsed_time);
				printf("——————————————\n", elapsed_time);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;
		case 0:
			printf("Game over\n");
			break;
		default:
			printf("选择错误请重新选择\n");
			break;
		}
	} while (input);
	
	return 0;
}