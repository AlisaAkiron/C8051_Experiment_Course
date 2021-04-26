#include <c8051f020.h>

// 外部晶振初始化
void Oscillator_Init()
{
	int i = 0;
	OSCXCN = 0x67;			   // 配置成外部晶体振荡器
	for (i = 0; i < 3000; i++) // 等待1ms以上，至少循环3000次
	{
	}
	while ((OSCXCN & 0x80) == 0) // 有效标志位为1跳出循环
	{
	}
	OSCICN = 0x08; // 切换到外部振荡器
}

// 禁用看门狗
void Disable_Watchdog()
{
	EA = 0;
	WDTCN = 0xDE;
	WDTCN = 0xAD;
	EA = 1;
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

// 左循环函数
void shifting_left()
{
	int i;
	P5 = 0xFE; //P5 = 1111 1110 先置最右边的灯亮
	for (i = 0; i < 8; i++)
	{
		delay(1000);
		P5 <<= 1;		// 左移1位，左移后最右边补0
		P5 = P5 | 0x01; // 做一个位或运算使最右边为1
	}
}

// 右循环函数
void shifting_right()
{
	int i;
	P5 = 0x7F; //P5 = 0111 1111 先置最左边的灯亮
	for (i = 0; i < 8; i++)
	{
		delay(1000);
		P5 >>= 1;		// 右移一位，右移后最右边补0
		P5 = P5 | 0x80; // 做一个位或运算使最左边为1
	}
}

// 交替闪灯函数
// INP t: 闪灯次数
void flicker_change(unsigned int t)
{
	unsigned int i;
	for (i = 0; i < t; i++)
	{
		P5 = 0xaa; //P5 = 1010 1010
		delay(1000);
		P5 = 0x55; //P5 = 0101 0101
		delay(1000);
	}
}

// 全亮闪灯函数
// INP t: 闪灯次数
void flicker(unsigned int t)
{
	unsigned int i;
	for (i = 0; i < t; i++)
	{
		P5 = 0; //灯全亮
		delay(1000);
		P5 = 0xff; //灯全灭
		delay(1000);
	}
}

void main()
{
	Oscillator_Init();
	Disable_Watchdog();
	while (1)
	{
		flicker(4);
		shifting_right();
		shifting_left();
		flicker_change(4);
	}
}
