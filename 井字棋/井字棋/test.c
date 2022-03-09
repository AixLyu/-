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
	char board[3][3] = { 0 };     //全空
	InitBoard(board, ROW, COL);  //初始化
	printf("1 1|1 2|1 3\n---|---|---\n2 1|2 2|2 3\n---|---|---\n3 1|3 2|3 3\n\n");  
	DisplayBoard(board, ROW, COL);//打印
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
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("三子棋，坐标如下，两数字之间加空格\n");
				game();
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
			    printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
