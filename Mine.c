#include"game.h"

void menu()
{
	printf("                  ��Ϸ�˵�                    \n");
	printf("=============================================\n");
	printf("1. ��ʼ��Ϸ\n");
	printf("0. �˳���Ϸ\n");
	printf("=============================================\n");
}

void meun2()
{
	printf("                ѡ����Ϸģʽ                    \n");
	printf("=============================================\n");
	printf("1. �����Ѷ�\n");
	printf("2. �м��Ѷ�\n");
	printf("3. �߼��Ѷ�\n");
	printf("4. �鿴���а�\n");
	printf("5. ����\n");
	printf("6. ������һ��Ŀ¼  \n");
	printf("=============================================\n");
}


void meun3()
{
	printf("                ����                       \n");
	printf("=============================================\n");
	printf("1. ������а�\n");
	printf("2. ���ɶ��� \n");
	printf("3. ������һ��Ŀ¼  \n");
	printf("=============================================\n");
}

void game()
{
	char mine[ROWS][COLS];//��Ų��úõ���
	char show[ROWS][COLS];//����Ų�����׵���Ϣ

	//��ʼ��������ʵ��
	initialization(mine, ROWS, COLS, '0');
	initialization(show, ROWS, COLS, '*');

	//��ӡ���̺���ʵ��
	Print_chessboard(show, ROW, COL);


	//������
	Lay_mines(mine, ROW, COL);

	Print_chessboard(mine, ROW, COL); //����


	//�׵��Ų�
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
				// ��¼����ǰ��ʱ��
				start = time(NULL);
				game();//����
				// ��¼���غ��ʱ��
				end = time(NULL);
				// ��������ʱ�䣨�룩
				elapsed_time = difftime(end, start);

				printf("����������������������������\n", elapsed_time);
				printf("|��ʱ��%.2f ��|\n", elapsed_time);
				printf("����������������������������\n", elapsed_time);
				
				break;
			case 2:    //�м�Ϊ16*16������40����
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("����,δʵ��,����н̽���\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				break;
			case 3:            //�߼�Ϊ16*30������99����
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("����,δʵ��,����н̽���\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

				break;
			case 4:
				displayLeaderboard();
				printf("\n\n\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				break;
			
			case 5:
				meun3();
				printf("��ѡ��������:> ");
				scanf("%d", &set);
				switch (set)
				{
				case 1:
					while (getchar() != '\n'); // ������뻺��
					printf("ȷ��������а��� Y/N\n");
					scanf("%c", &SETE);
					if (SETE == 'Y')
					{
						clearLeaderboard();
						printf("����������а�\n");

					}
					else
					{
						printf("����ȡ��������а�\n");
					}
					// ��ʾ���а�
					displayLeaderboard();
					printf("\n\n\n");
					break;
				case 2:         //�Զ��弶������Լ��趨������С������������������С���ܳ���24 * 30)
					printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
					printf("����,δʵ��,����н̽���\n");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	

	
	return 0;
}