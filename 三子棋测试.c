#define _CRT_SECURE_NO_WARNINGS 1
#include"���������.h"
#include<stdio.h>
#include<stdlib.h>//rand��������һ�����ֵ
#include<time.h>
//��ʼ��
void chushihua(char qipan[hang][lie], int hang1, int lie1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang1; i++)
	{
		for (j = 0; j < lie1; j++)
		{
			qipan[i][j] = ' ';//ÿ��Ԫ�س�ʼ��
		}
	}

}
//��ӡ����������
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
//����ƶ�
void wanjia(char qipan[hang][lie], int hang1, int lie1)
{
	
		int x, y;
		printf("����ƶ�:>\n"); 
		while (1)
		{
			printf("���:* ����:+\n");
			printf("������Ҫ�µ�����:>");
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
					printf("�����걻ռ��\n");
				}
			}
			else
			{
				printf("����Ƿ�������������\n");
			}
		}
}
//�����ƶ�
void diannao(char qipan[hang][lie], int hang1, int lie1)
{
	printf("�����ƶ�:>\n");	
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
//����1��ʾ��������
//����0��ʾû��
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
				return 0;//û��
			}

		}

	}
	return 1;//����

}

//�ж�����Ƿ���Ӯ
char panduan(char qipan[hang][lie], int hang1, int lie1)
{
	int i = 0;
	for(i=0;i<hang;i++)//������
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != ' ')
		{
			return qipan[i][1];
		}
	}
	for (i = 0; i < lie; i++)//������
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != ' ')
		{
			return qipan[1][i];
		}
	}
	//�����Խ���
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	//�ж�ƽ��
	if (1 == manqipan(qipan, hang, lie))
	{
		return 'C';
	}
	if (0 == manqipan(qipan, hang, lie))
	{
		return 'D';
	}
}