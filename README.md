# 51单片机实验课代码

这是宁波大学单片机实验课的代码

## 关于

我的单片机实验课代码，课号是 `102G05A` ，不能保证题目是不是一样的，请参考你的实验指导书 

我也是边学边做，不能保证我的代码一定是最优解，也不保证一定正确

每一个实验文件夹里面有个 README ，是简略版本的实验指导书上的内容

## 实验环境

单片机：兼容C51标准的好像都能跑

开发环境：[Keil μVision C51](https://www.keil.com/demo/eval/c51.htm) V5.27.1.0 （ V5以上一般都可，V4不保证兼容 ）

代码编辑器：Visual Studio Code （配合 Keil Assistant 插件和 C/C++ 系列插件）（ Keil的这个编辑器有够垃圾的 ）

程序下载：学校的板子 用的 `U-EC6C8051F` 仿真器，可以用 [`Silicon Laboratories FLASH Programming Utilities`](https://www.silabs.com/documents/login/software/utildll.exe) 下载程序，需要先使用 Keil 编译出 `.hex` 文件，然后将其下载进单片机

***关于程序下载***

如果是学校的板子带一个 EC-6 的，用下载器时 `Debug Interface` 选择 `JTAG` ，然后点 `Connect` 应该就能连上了

切换到 `Download Hex File/Go/Stop` 标签，先选择一个 `.hex` 文件，然后下载即可，下载完后点 `Go` 开始运行

切换到 `Flash Erase` 标签，可以清除单片机上的所有代码

## 许可证

本仓库使用 [DO WHAT THE F**K YOU WANT TO PUBLIC LICENSE(WTFPL, 你TM爱干啥干啥)](./LICENSE) 许可证授权