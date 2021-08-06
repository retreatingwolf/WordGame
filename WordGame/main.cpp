#include <Windows.h>
#include <string>
#include <sstream>//字符串的拼接
using namespace std;

#include "GameController.h"
#include "GameWorld.h"
#include "GameCore.h"
#include "RandomUtill.h"

extern void InitConsolo();
extern void SetTitle(string title);
extern void SetColor(char bkcolor,char fontcolor);
extern void SetWinSize(int width, int height);

int main(void)
{
	InitConsolo();

	/*游戏控制器单例对象*/
	GameController::GetInstance()->GameStart();//注意静态成员变量的使用方法
	
	system("pause");
	return 0;
}

void SetTitle(string title)
{
	stringstream cmd;
	cmd << "Title ";
	cmd << title;
	system(cmd.str().c_str());//将string类型转化为const char类型
}

void SetColor(char bkcolor, char fontcolor)
{
	stringstream cmd;
	cmd << "color ";
	cmd << bkcolor;
	cmd << fontcolor;
	system(cmd.str().c_str());
}

void SetWinSize(int width, int height)
{
	stringstream cmd;
	cmd << "mode con ";
	cmd << "cols=" << width;
	cmd << "lines=" << height;
	system(cmd.str().c_str());
}

void InitConsolo()
{
	//控制台参数设计
	//1.设置标题
	SetTitle("都市浮生记");
	//2.设置背景色和前景色
	SetColor('1', 'F');
	//3.设置窗口大小
	SetWinSize(64, 38);
}


/*
1.学会设置标题
2.system函数理解更加深
3.字符串拼接的方法
4.菜单界面设计方法（多级菜单的设计方法）
5.游戏主循环的设置和技巧
6.升入理解面向对象
7.游戏信息的展示方法
8.map的使用方法
*/
/*
单例设计模式
1.使用饥饿式单例设计模式
2.此模式线程不安全，但此项目没有用到多线程
*/

/*
1.这种一层套一层的大程序，写一点就必须调试一点，想尽一切办法调试，
否则写了一大堆，结果没法运行，编译器甚至不报错，也没法调试，见
了鬼了简直，事倍功半，一定要写一点就调试一点！！！
2.类头文件多起来了，一定要小心谨慎，没有用到的头文件就不要包含
但是在cpp文件中导入头文件就不会出现循环引用的后果
3.在A类想要调用B类的某一个封装函数的办法！将B中的函数改为static类型
并让外部可以调用
4.使用map类来记录游戏物品的数据（详见GameWorld.h）好处是便于查询
5.只在类内部调用的函数就设置为private类型
*/
