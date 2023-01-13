#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"三子棋测试.h"
#include<stdlib.h>
#include<time.h>//time
//开始菜单
void kaishi()
{
	printf("****************************\n");
	printf("********    菜单    ********\n");
	printf("******** 1.开始游戏 ********\n");
	printf("******** 2.退出游戏 ********\n");
	printf("****************************\n");
}
//游戏主体
void youxizhuti()
{
	char qipan[hang][lie] = { 0 };//存储棋盘信息
	chushihua(qipan, hang, lie);//棋盘初始化
	dayinqipan(qipan, hang,lie);//打印棋盘
	char ret = 0;//A—玩家赢 B—电脑赢 C—平局 D—继续
	while (1)
	{
		
		wanjia(qipan,hang,lie);//玩家移动
		dayinqipan(qipan, hang, lie);//显示
		ret = panduan(qipan, hang, lie);
		if (ret != 'D')
		{
			break;
		}
		diannao(qipan,hang,lie);//电脑移动
		dayinqipan(qipan, hang, lie);//显示
		ret = panduan(qipan, hang, lie);
		if (ret != 'D')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	if (ret == '+')
	{
		printf("电脑赢\n");
	}
	if (ret == 'C')
	{
		printf("平局\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));//rand()%(n-m+1)+m——生成m到n的随机数
	int kaishizhi=0;
	do
	{	
		printf("请选择>:");
		scanf("%d", &kaishizhi);
		switch (kaishizhi)
		{
		case 1:
			youxizhuti();
			break;
		case 2:
			printf("退出游戏成功\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (kaishizhi != 1 && kaishizhi != 2);

}
int main()
{
	kaishi();
	test();
	return 0;
}