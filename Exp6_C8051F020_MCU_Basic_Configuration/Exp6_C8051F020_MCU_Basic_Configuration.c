#include <c8051f020.h>

sbit P21 = P2 ^ 1;

//外部12MHz晶振初始化
void Oscillator_Init()
{
    int i = 0;
    OSCXCN = 0x67;             //配置成外部晶体振荡器
    for (i = 0; i < 3000; i++) //等待1ms以上，至少循环3000次
    {
    }
    while ((OSCXCN & 0x80) == 0) // 有效标志位为1跳出循环
    {
    }
    OSCICN = 0x0c; //切换到外部振荡器
}

//延迟函数
void delay(unsigned int t)
{
    unsigned int j;
    while (t--)
    {
        for (j = 0; j < 100; j++)
        {
        }
    }
}

//I/O口初始化程序
void Port_IO_Init()
{
    XBR0 = 0x02;    //SPI
    XBR1 = 0x1E;    //T0，T1，INT0，INT1
    XBR2 = 0x40;    //XBR2.6=1  交叉开关使能
    P1MDOUT = 0x1F; //P1.5,P1.6,P1.7漏极开路
    P1 = 0xE0;      //P1.5，P1.6，P1.7逻辑1；
    P1MDIN = 0x1F;  //P1.5，P1.6，P1.7模拟输入
}

//禁用看门狗程序
void Disable_Watchdog()
{
    EA = 0;
    WDTCN = 0xDE;
    WDTCN = 0xAD;
}

void main()
{
    Oscillator_Init();
    Disable_Watchdog();
    Port_IO_Init();

    P2MDOUT = 0x02; //推挽方式输出
    P21 = 0;
    while (1)
    {
        delay(15);
        P21 = ~P21;
    }
}
