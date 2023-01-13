#define hang 3
#define lie 3

//初始化
void chushihua(char	qipan[hang][lie],int hang1,int lie1);
//打印棋盘        
void dayinqipan(char qipan[hang][lie], int hang1, int lie1);
//玩家移动
void wanjia(char qipan[hang][lie], int hang1,int lie1);
//机器移动
void diannao(char qipan[hang][lie], int hang1,int lie1);
//判断是否输赢
char panduan(char qipan[hang][lie],int hang1, int lie1);