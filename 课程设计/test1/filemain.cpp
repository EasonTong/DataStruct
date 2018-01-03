#include <iostream>
#include <conio.h>

using namespace std;


//http://tieba.baidu.com/p/1624634640  颜色调用

/*用 system("color 0A"); 
其中color后面的0是背景色代号，A是前景色代号。各颜色代码如下： 
	0=黑色 
	1=蓝色 
	2=绿色 
	3=湖蓝色 
	4=红色 
	5=紫色 
	6=黄色 
	7=白色 
	8=灰色 
	9=淡蓝色 
	A=淡绿**=淡浅绿色 
	C=淡红色 
	D=淡紫色 
	E=淡黄色 
	F=亮白色 */


int main()
{
	system("color 0A");
	cout << "Hello World" << endl;

	//system("color 07");
	cout << "Hello World" << endl;

	char a;
	a = getch();
	cout << a << endl;
	return 0;
}

/*控制台的界面只有单调的黑白两色，即使有了color，也不过是16种组合，也只能控制整个控制台的颜色。能否实现对特定部分的文字使用特定颜色呢？将教会你把控制台变得绚丽多彩。


	首先需要认识一个API函数FillConsoleOutputAttribute，它能实现给部分文字上色


	参数信息：


	FillConsoleOutputAttribute(

	HANDLE hOutputHandle,

	WORD wAttribute,

	DWORD nLength,

	COORD dwWriteCoord,

	LPDWORD lpNumberOfAttrsWritten

	)


	参数详解：


	HANDLE hOutputHandle：

	控制台输出句柄，不多说了


	WORD wAttribute：

	颜色属性，具体见后文


	DWORD nLength：

	上色的字符串长度


	COORD dwWriteCoord：

	上色坐标（COORD在Windows.h中定义）


	LPDWORD
	lpNumberOfAttrsWritten：

	DWORD型的指针，输出成功上色的长度


	想必大家都已经能猜到效果了吧，那么其他参数都没有太大的问题，重要的参数是WORD
	wAttribute。那么这个参数可取的值有：


	FOREGROUND_BLUE 蓝色

	FOREGROUND_GREEN 绿色

	FOREGROUND_RED 红色

	FOREGROUND_INTENSITY 前景色加强

	BACKGROUND_BLUE 蓝色背景

	BACKGROUND_GREEN 绿色背景

	BACKGROUND_RED 红色背景

	BACKGROUND_INTENSITY 背景色加强

	COMMON_LVB_REVERSE_VIDEO 反色


	光看可能不清楚，举个例子就明白了。如果我想要蓝色文字、绿色背景，就这样写：


	WORD
	wAttribute=FOREGROUND_BLUE|BACKGROUND_GREEN;


明白了吧，每个想要的属性之间用“|”符号连接。其他效果请自行测试。


	示例代码：


	给(5,1)处的10个文字涂上绿色背景、红色文字：


	HANDLE hOut;

COORD pos;

WORD color;

DWORD written;

hOut=GetStdHandle(STD_OUTPUT_HANDLE);

color=FOREGROUND_RED|BACKGROUND_GREEN;

pos.X=5;

pos.Y=1;

FillConsoleOutputAttribute(hOut,color,10,pos,&written);


现在，你的控制台是否已经绚丽多彩了呢？





	讲述了如何给特定的文字加上颜色。但当我们需要输出很多带颜色的文字的时候，用FillConsoleOutputAttribute就不是好办法了。解决办法之一，就是用system函数调用color来实现，不过这样的话之前输出的颜色也会丢失。能不能有简单快速的办法呢？？《彩色控制台》系列之②，将教会你在保留原有颜色的情况下，对大面积带色文字的快速输出。


	最有效的解决办法，就是使用API函数SetConsoleTextAttribute：


	BOOL
	SetConsoleTextAttribute(

	HANDLE hConsoleOutput,

	WORD wAttributes

	)


	参数详解：


	HANDLE hConsoleOutput：

	控制台输出句柄，不多废话


	WORD wAttributes：

	颜色属性，具体参考系列文章之①的附表


	那么API执行成功之后，所有的输出（printf、cout等）都会带上这个颜色，其他区域不受输出内容的影响。


	示例代码：


	HANDLE hOut;

WORD color;

hOut=GetStdHandle(STD_OUTPUT_HANDLE);

color=FOREGROUND_RED|BACKGROUND_GREEN;

SetConsoleTextAttribute(hOut,color);

printf("Hello!");


如果能够熟练的使用这个API函数，能简化不少代码。











	随着两个最主要的函数出台，《彩色控制台》系列的文章核心已经讲完了。如果有认真看的朋友，现在的控制台一定是五彩斑斓的吧！不过大家可以看到，单单给一个部分变色就用了5行代码，显得非常臃肿，效率也不高。本章提供了自写的3个函数，能够极大地提高颜色方面控制的效率。


	回复2楼2012-05-31 14:19举报 |
	个人企业举报
	垃圾信息举报

	xiaoboaicyuyan
	四年级7


	CursorGo自写函数：


	头文件：Windows.h

	功能：更改光标位置

	用法：CursorGo(x,y);

具体：x,y为int型，分别是X坐标和Y坐标


	void CursorGo(int x,int
	y)

{

	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos={x,y};

	SetConsoleCursorPosition(hOutput,pos);

}


ClearScreen自写函数：


	头文件：Windows.h

	功能：清屏

	用法：ClearScreen(NULL);或ClearScreen(wAttributes);

具体：参数一为NULL时，直接清屏，使用默认背景色；参数一为颜色属性时，清屏并使用颜色属性（不设置为默认颜色）


	void ClearScreen(WORD
	wAttributes)

{

	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;

	GetConsoleScreenBufferInfo(hOutput,&bInfo);

	COORD home={0,0};

	unsigned long size=bInfo.dwSize.X*bInfo.dwSize.Y;

	if(!wAttributes) wAttributes=bInfo.wAttributes;

	FillConsoleOutputAttribute(hOutput,wAttributes,size,home,NULL);

	FillConsoleOutputCharacter(hOutput,' ',size,home,NULL);

}


PrintText自写函数：


	头文件：Windows.h

	功能：在指定坐标输出带有指定颜色的文字

	用法：PrintText(text,x,y,wAttributes);或PrintText(text,x,y,NULL);

具体：参数一为字串符指针；参数二、三为int型，指定坐标；参数四为NULL时，输出的文字为默认颜色；参数四为颜色属性时，输出的文字为执行颜色（不设置为默认颜色）


	void PrintText(LPCTSTR
	text,int x,int y,WORD wAttributes)

{

	DWORD task;

	COORD pos={x,y};

	int slen=strlen(text);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;

	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hOutput,&bInfo);

	if(!wAttributes) wAttributes=bInfo.wAttributes;

	WriteConsoleOutputCharacter(hOutput,text,slen,pos,&task);

	FillConsoleOutputAttribute(hOutput,wAttributes,slen,pos,&task);

}








颜色属性是由各个常数相加组成的，要得到输出效果就只有查表然后手工拼凑而成，效率很低。笔者写了一个工具，可以快速组合出所需的效果，在组合的过程中可直接预览效果。放到这系列文章中，也是磨刀不误砍柴工。


	界面预览：

























	左边是常数列表，使用左键单击即可选定


	右边是预览效果，可直接查看所选常数组合的最终效果


	下边是操作框，列出了所选常数组合的结果，可以按Copy复制到剪贴板。第一行是10进制，第二行是16进制。


	直接鼠标操作即可。


	另外，此工具在CMD下直接调用无法正常运行。*/