#include <c8051f020.h>

sbit P21 = P2 ^ 1;

// 外部晶振初始化
void Oscillator_Init()
{
    int i = 0;
    OSCXCN = 0x67;             // 配置成外部晶体振荡器，0x67 为 12Mhz，0x77 为 6Mhz
    for (i = 0; i < 3000; i++) // 等待1ms以上，至少循环3000次
    {
    }
    while ((OSCXCN & 0x80) == 0) // 有效标志位为1跳出循环，即 XTLVLD = 1
    {
    }
    OSCICN = 0x08; // 切换到外部振荡器
}

// 延迟函数
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
    XBR0 = 0x02;    // SPI | XBR0 = 0000 0010
    XBR1 = 0x1E;    // T0(1)，T1(3)，INT0(2)，INT1(4) | XBR1 = 0001 1110
    XBR2 = 0x40;    // 交叉开关使能 | XBR2.6 = 1
    P1MDOUT = 0x1F; // P1.5,P1.6,P1.7 输出模式配置 漏极开路 | P1MDOUT = 0001 1111
    P1 = 0xE0;      // P1.5，P1.6，P1.7 置1 | P1 = 1110 0000
    P1MDIN = 0x1F;  // P1.5，P1.6，P1.7 输入模式配置 模拟输入 | P1MDIN = 0001 1111
}

// 禁用看门狗
void Disable_Watchdog()
{
    EA = 0;       // 禁止所有中断，下两条语句须在4时钟周期内，防止打断
    WDTCN = 0xDE; // 关闭看门狗
    WDTCN = 0xAD;
    EA = 1; // 恢复中断
}

void main()
{
    Oscillator_Init();
    Disable_Watchdog();
    Port_IO_Init();

    P2MDOUT = 0x02; // P2.1 推挽方式输出
    P21 = 0;
    while (1)
    {
        delay(15);
        P21 = ~P21;
    }
}
