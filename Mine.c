#include"game.h"

void menu()
{
	printf("++++++++++++++++++++++++++++++++\n");
	printf("********************************\n");
	printf("*****	  0.OUT   	   *****\n");
	printf("*****	  1.PLAY  	   *****\n");
	printf("********************************\n");
	printf("++++++++++++++++++++++++++++++++\n");
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
	Print_chessboard(mine, ROW, COL);


	//布置雷
	Lay_mines(mine, ROW, COL);

	

	//类的排查
	screening(show, mine, ROW, COL);

}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));


	do
	{
		menu();
		printf("Please select:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
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