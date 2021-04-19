#include <stdio.h>
#include <intrins.h>
#include <ABSACC.H>

unsigned char data a[10]; //声明变量片内数据存储区
unsigned char data b[10];
unsigned char code *ptr0;  //声明指向程序存储区的指针变量
unsigned char xdata *ptr1; //声明指向外部数据存储区的指针变量
unsigned char i;

void main()
{
    ptr0 = 0x0000; //指向程序存储区地址为0x0010
    ptr1 = 0x0200; //指向外部数据存储区地址为0x0200

    for (i = 0; i < 10; i++)
    {
        DBYTE[0x30 + i] = a[i];
        DBYTE[0x50 + i] = b[i];
    }

    for (i = 0; i < 10; i++) //将 程序存储器 的数据搬运到 片内数据存储区
    {
        a[i] = *ptr0;
        ptr0++;
    }

    for (i = 0; i < 10; i++) //将 片外数据存储区 的数据搬运到 片内数据存储区
    {
        b[i] = *ptr1;
        ptr1++;
    }

    for (i = 0; i < 10; i++)
    {
        DBYTE[0x30 + i] = a[i];
        DBYTE[0x50 + i] = b[i];
    }

    while (1)
    {
    }
}