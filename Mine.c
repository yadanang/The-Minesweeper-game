#include"game.h"

void menu()
{
	printf("=============================================\n");
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
	printf("4. ���ɶ��� \n");
	printf("2. �鿴���а�\n");
	printf("3. ����\n");
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
	//Print_chessboard(mine, ROW, COL);


	//������
	Lay_mines(mine, ROW, COL);

	

	//����Ų�
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	
	return 0;
}