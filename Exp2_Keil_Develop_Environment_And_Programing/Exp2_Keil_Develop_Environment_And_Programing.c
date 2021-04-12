#include "ABSACC.H"

unsigned char a0 = 5; // 加数1-高位-0x30
unsigned char a1 = 6; // 加数1-低位-0x31
unsigned char b0 = 1; // 加数2-高位-0x40
unsigned char b1 = 9; // 加数2-低位-0x41

unsigned char ans[3]; // 加法结果-0x50 0x51 0x52

int i;

void main()
{
    DBYTE[0x30] = a0;
    DBYTE[0x31] = a1;
    DBYTE[0x40] = b0;
    DBYTE[0x41] = b1;

    // 计算结果
    // ans[0] 为最高位
    ans[2] = (a1 + b1) % 10;
    ans[1] = ((a1 + b1) / 10 + a0 + b0) % 10;
    ans[0] = (a0 + b0) / 10;

    // 输出数据绑定存储空间
    for (i = 0; i <= 2; i++)
    {
        DBYTE[0x50 + i] = ans[i];
    }
}