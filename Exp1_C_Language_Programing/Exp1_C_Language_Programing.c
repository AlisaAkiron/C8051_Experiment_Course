#include "REG51.H"
#include "stdio.h"

void delay(int m);

void main()
{
    int i = 0;
    int sum = 0;
    int j = 0;
    while(1)
    {
        i = i + 1;
        TI = 1;         // 开启串口
        printf("i = %d\n", i);
        if(i >= 3)
        {
            printf("i is bigger than 5: true\n");
        }
        else
        {
            printf("i is bigger than 5: false\n");
        }
        
        for(j = 1; j <= 10; j++)
        {
            sum = sum + j;
        }
        printf("sum = %d\n", sum);
        sum = 0;

        TI = 0;         // 串口发送请求完毕
        delay(100);
        P1 = i;         // 从端口 P1 输出
    }
}

void delay(int m)
{
    int x, y;
    for(y = 0; y <= 10000; y++)
    {
        for(x = 0; x <= m; x++)
        {
        }
    }
}
