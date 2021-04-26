#include <ZLG7289.h>
#include <intrins.h>

unsigned char Key = 0xFF;
unsigned char currentCursorPositon = 7; // 显示数码管显示变量
unsigned char flag = 0;                 // Key=15 调整一次有效
unsigned char flicker = 0xFE;           // 选中的数码闪烁变量

// 外部晶振初始化
void Oscillator_Init()
{
    int i = 0;
    OSCXCN = 0x77;             // 配置成外部晶体振荡器，0x67 为 12Mhz，0x77 为 6Mhz
    for (i = 0; i < 3000; i++) // 等待1ms以上，至少循环3000次
    {
    }
    while ((OSCXCN & 0x80) == 0) // 有效标志位为1跳出循环，即 XTLVLD = 1
    {
    }
    OSCICN = 0x08; // 切换到外部振荡器
}

// 禁用看门狗
void Disable_Watchdog()
{
    EA = 0;       // 禁止所有中断，下两条语句须在4时钟周期内，防止打断
    WDTCN = 0xDE; // 关闭看门狗
    WDTCN = 0xAD;
    EA = 1; // 恢复中断
}

// 延迟函数
void delay(unsigned int t)
{
    unsigned int i;
    while (t--)
    {
        for (i = 0; i < 700; i++)
        {
        }
    }
}

// IO初始化
void Port_IO_Init()
{
    XBR2 = 0x40;    // 交叉开关开启
    P3MDOUT = 0xFF; // 数字推挽输出
    EIE2 = 0x20;    // EX7=1
}

// 外部中断7
void INT7_ISR(void) interrupt 19
{
    Key = ZLG7289_Key(); // 键盘值获取
    P3IF &= ~0x80;
    flag = 0;
    delay(5);
}

void Change_Position() // 闪烁位移
{
    currentCursorPositon++;
    ZLG7289_Flash(flicker);       //  闪烁
    flicker = _crol_(flicker, 1); // 循环左移函数
    flag = 1;
    if (currentCursorPositon > 7)
    {
        currentCursorPositon = 0;
    }
}

void Set_Number(unsigned char Key1) // 根据键入获取数字或重置
{
    if (Key1 >= 0 && Key1 <= 9) // 1-9输入数字 并重置Key地址
    {
        ZLG7289_Download(1, currentCursorPositon, 0, Key);
        Key = 0xff;
    }
}

int main()
{
    unsigned char i;
    Disable_Watchdog(); // 禁用看门狗定时器
    Oscillator_Init();  // 外部晶振初始化
    Port_IO_Init();     // IO初始化
    ZLG7289_Reset();    // 复位（清除）指令
    ZLG7289_Init(50);   // ZLG7289 初始化
    delay(1000);
    ZLG7289_Reset(); // 复位（清除）指令
    for (i = 0; i < 8; i++)
    {
        ZLG7289_Download(1, i, 0, 0); // 所有数码管显示0
    }
    delay(100);

    while (1)
    {
        if (Key == 15 && flag == 0) // 按键15开始闪烁与输入
        {
            Change_Position();
        }

        Set_Number(Key); // 根据键入获取数字或重置
    }
}