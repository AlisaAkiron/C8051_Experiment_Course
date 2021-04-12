#include <stdio.h>
#include <intrins.h>

unsigned char data a[10];
_at_0x0030; //申明变量片内数据存储区
unsigned char data b[10];
_at_0x0050;
unsigned char code *ptr0;  //申明指向程序存储区的指针变量
unsigned char xdata *ptr1; //申明指向外部数据存储区的指针变量
unsigned char i;

void main()
{
    ptr0 = 0x0010;           //指向程序存储区地址为0x0010
    ptr1 = 0x0200;           //指向程序存储区地址为0x0200
    for (i = 0; i < 10; i++) //将程序存储器的数据搬运到数据存储区：将指定程序存储器地址开始的10个字节搬运到片内数据存储区。
    {
        a[i] = *ptr0;
        ptr0++;
    }
    for (i = 0; i < 10; i++) //数据存储区内的数据搬运：将指定片外数据存储器地址开始的10个字节搬运到片内数据存储区。
    {
        b[i] = *ptr1;
        ptr1++;
    }
    while (1)
    {
    }
}