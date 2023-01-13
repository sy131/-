#define _CRT_SECURE_NO_WARNINGS 1
#include"三子棋测试.h"
#include<stdio.h>
#include<stdlib.h>//rand——生成一个随机值
#include<time.h>
//初始化
void chushihua(char qipan[hang][lie], int hang1, int lie1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang1; i++)
	{
		for (j = 0; j < lie1; j++)
		{
			qipan[i][j] = ' ';//每个元素初始化
		}
	}

}
//打印三子棋棋盘
void dayinqipan(char qipan[hang][lie], int hang1, int lie1)
{
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < lie; j++)
		{
			
			printf(" %c ", qipan[i][j]);
			if (j < lie-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < hang - 1)
		{
			for (int j = 0; j < lie; j++)
			{
				printf("---");
				if (j < lie - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//玩家移动
void wanjia(char qipan[hang][lie], int hang1, int lie1)
{
	
		int x, y;
		printf("玩家移动:>\n"); 
		while (1)
		{
			printf("玩家:* 电脑:+\n");
			printf("请输入要下的坐标:>");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= hang && y >= 1 && y <= lie)
			{
				if (qipan[x - 1][y - 1] == ' ')
				{
					qipan[x - 1][y - 1] = '*';
					break;
				}
				else
				{
					printf("该坐标被占用\n");
				}
			}
			else
			{
				printf("坐标非法，请重新输入\n");
			}
		}
}
//机器移动
void diannao(char qipan[hang][lie], int hang1, int lie1)
{
	printf("电脑移动:>\n");	
	while(1)
	{
		int x = rand() % hang1;
		int y = rand() % lie1;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = '+';
			
			break;
		}
	}
}
//返回1表示棋盘满了
//返回0表示没满
int manqipan(char qipan[hang][lie], int  hang1, int lie1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;//没满
			}

		}

	}
	return 1;//满了

}

//判断玩家是否输赢
char panduan(char qipan[hang][lie], int hang1, int lie1)
{
	int i = 0;
	for(i=0;i<hang;i++)//横三行
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != ' ')
		{
			return qipan[i][1];
		}
	}
	for (i = 0; i < lie; i++)//竖三列
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != ' ')
		{
			return qipan[1][i];
		}
	}
	//两个对角线
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	//判断平局
	if (1 == manqipan(qipan, hang, lie))
	{
		return 'C';
	}
	if (0 == manqipan(qipan, hang, lie))
	{
		return 'D';
	}
}