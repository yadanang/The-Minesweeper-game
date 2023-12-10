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
	char mine[ROWS][COLS];//��Ų��úõ���
	char show[ROWS][COLS];//����Ų�����׵���Ϣ

	//��ʼ��������ʵ��
	initialization(mine, ROWS, COLS, '0');
	initialization(show, ROWS, COLS, '*');

	//��ӡ���̺���ʵ��
	Print_chessboard(show, ROW, COL);
	Print_chessboard(mine, ROW, COL);


	//������
	Lay_mines(mine, ROW, COL);

	

	//����Ų�
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	
	return 0;
}