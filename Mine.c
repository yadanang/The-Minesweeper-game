#include"game.h"

void menu()
{
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
	printf("4. 查看排行榜\n");
	printf("5. 设置\n");
	printf("6. 返回上一级目录  \n");
	printf("=============================================\n");
}


void meun3()
{
	printf("                设置                       \n");
	printf("=============================================\n");
	printf("1. 清空排行榜\n");
	printf("2. 自由定义 \n");
	printf("3. 返回上一级目录  \n");
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


	//布置雷
	Lay_mines(mine, ROW, COL);

	Print_chessboard(mine, ROW, COL); //测试


	//雷的排查
	screening(show, mine, ROW, COL);

}

int main()
{
	char SETE = 0;
	int b = 0 ,set = 0;
	int input = 0; 
	int input2 = 0;

	srand((unsigned int)time(NULL));

	
	do
	{
		E: menu();
		printf("Please select:>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			M:meun2();
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
			case 2:    //中级为16*16个方块40个雷
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("不会,未实现,求大佬教教我\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				break;
			case 3:            //高级为16*30个方块99个雷
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("不会,未实现,求大佬教教我\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				break;
			case 4:
				displayLeaderboard();
				printf("\n\n\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				break;
			
			case 5:
				meun3();
				printf("请选择并输入编号:> ");
				scanf("%d", &set);
				switch (set)
				{
				case 1:
					while (getchar() != '\n'); // 清空输入缓冲
					printf("确认清除排行榜吗？ Y/N\n");
					scanf("%c", &SETE);
					if (SETE == 'Y')
					{
						clearLeaderboard();
						printf("你已清空排行榜\n");

					}
					else
					{
						printf("你已取消清空排行榜\n");
					}
					// 显示排行榜
					displayLeaderboard();
					printf("\n\n\n");
					break;
				case 2:         //自定义级别可以自己设定雷区大小和雷数，但是雷区大小不能超过24 * 30)
					printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf("不会,未实现,求大佬教教我\n");
					printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					break;
				case 3:
					system("cls");
					goto M;
					break;
				}
				
				break;
			case 6:
				goto E;
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