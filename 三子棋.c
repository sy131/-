#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"���������.h"
#include<stdlib.h>
#include<time.h>//time
//��ʼ�˵�
void kaishi()
{
	printf("****************************\n");
	printf("********    �˵�    ********\n");
	printf("******** 1.��ʼ��Ϸ ********\n");
	printf("******** 2.�˳���Ϸ ********\n");
	printf("****************************\n");
}
//��Ϸ����
void youxizhuti()
{
	char qipan[hang][lie] = { 0 };//�洢������Ϣ
	chushihua(qipan, hang, lie);//���̳�ʼ��
	dayinqipan(qipan, hang,lie);//��ӡ����
	char ret = 0;//A�����Ӯ B������Ӯ C��ƽ�� D������
	while (1)
	{
		
		wanjia(qipan,hang,lie);//����ƶ�
		dayinqipan(qipan, hang, lie);//��ʾ
		ret = panduan(qipan, hang, lie);
		if (ret != 'D')
		{
			break;
		}
		diannao(qipan,hang,lie);//�����ƶ�
		dayinqipan(qipan, hang, lie);//��ʾ
		ret = panduan(qipan, hang, lie);
		if (ret != 'D')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	if (ret == '+')
	{
		printf("����Ӯ\n");
	}
	if (ret == 'C')
	{
		printf("ƽ��\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));//rand()%(n-m+1)+m��������m��n�������
	int kaishizhi=0;
	do
	{	
		printf("��ѡ��>:");
		scanf("%d", &kaishizhi);
		switch (kaishizhi)
		{
		case 1:
			youxizhuti();
			break;
		case 2:
			printf("�˳���Ϸ�ɹ�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (kaishizhi != 1 && kaishizhi != 2);

}
int main()
{
	kaishi();
	test();
	return 0;
}