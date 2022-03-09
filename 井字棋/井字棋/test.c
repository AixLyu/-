#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("****** 1.play  0.exit ******\n");
	printf("****************************\n");
}
void game()
{
	char ret = 0;
	char board[3][3] = { 0 };     //ȫ��
	InitBoard(board, ROW, COL);  //��ʼ��
	printf("1 1|1 2|1 3\n---|---|---\n2 1|2 2|2 3\n---|---|---\n3 1|3 2|3 3\n\n");  
	DisplayBoard(board, ROW, COL);//��ӡ
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
			break;
		PCMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("�����壬�������£�������֮��ӿո�\n");
				game();
				break;
		case 0:
				printf("�˳���Ϸ\n");
				break;
		default:
			    printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
