#include <iostream>
#include <conio.h>

using namespace std;


//http://tieba.baidu.com/p/1624634640  ��ɫ����

/*�� system("color 0A"); 
����color�����0�Ǳ���ɫ���ţ�A��ǰ��ɫ���š�����ɫ�������£� 
	0=��ɫ 
	1=��ɫ 
	2=��ɫ 
	3=����ɫ 
	4=��ɫ 
	5=��ɫ 
	6=��ɫ 
	7=��ɫ 
	8=��ɫ 
	9=����ɫ 
	A=����**=��ǳ��ɫ 
	C=����ɫ 
	D=����ɫ 
	E=����ɫ 
	F=����ɫ */


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

/*����̨�Ľ���ֻ�е����ĺڰ���ɫ����ʹ����color��Ҳ������16����ϣ�Ҳֻ�ܿ�����������̨����ɫ���ܷ�ʵ�ֶ��ض����ֵ�����ʹ���ض���ɫ�أ����̻���ѿ���̨���Ѥ����ʡ�


	������Ҫ��ʶһ��API����FillConsoleOutputAttribute������ʵ�ָ�����������ɫ


	������Ϣ��


	FillConsoleOutputAttribute(

	HANDLE hOutputHandle,

	WORD wAttribute,

	DWORD nLength,

	COORD dwWriteCoord,

	LPDWORD lpNumberOfAttrsWritten

	)


	������⣺


	HANDLE hOutputHandle��

	����̨������������˵��


	WORD wAttribute��

	��ɫ���ԣ����������


	DWORD nLength��

	��ɫ���ַ�������


	COORD dwWriteCoord��

	��ɫ���꣨COORD��Windows.h�ж��壩


	LPDWORD
	lpNumberOfAttrsWritten��

	DWORD�͵�ָ�룬����ɹ���ɫ�ĳ���


	��ش�Ҷ��Ѿ��ܲµ�Ч���˰ɣ���ô����������û��̫������⣬��Ҫ�Ĳ�����WORD
	wAttribute����ô���������ȡ��ֵ�У�


	FOREGROUND_BLUE ��ɫ

	FOREGROUND_GREEN ��ɫ

	FOREGROUND_RED ��ɫ

	FOREGROUND_INTENSITY ǰ��ɫ��ǿ

	BACKGROUND_BLUE ��ɫ����

	BACKGROUND_GREEN ��ɫ����

	BACKGROUND_RED ��ɫ����

	BACKGROUND_INTENSITY ����ɫ��ǿ

	COMMON_LVB_REVERSE_VIDEO ��ɫ


	�⿴���ܲ�������ٸ����Ӿ������ˡ��������Ҫ��ɫ���֡���ɫ������������д��


	WORD
	wAttribute=FOREGROUND_BLUE|BACKGROUND_GREEN;


�����˰ɣ�ÿ����Ҫ������֮���á�|���������ӡ�����Ч�������в��ԡ�


	ʾ�����룺


	��(5,1)����10������Ϳ����ɫ��������ɫ���֣�


	HANDLE hOut;

COORD pos;

WORD color;

DWORD written;

hOut=GetStdHandle(STD_OUTPUT_HANDLE);

color=FOREGROUND_RED|BACKGROUND_GREEN;

pos.X=5;

pos.Y=1;

FillConsoleOutputAttribute(hOut,color,10,pos,&written);


���ڣ���Ŀ���̨�Ƿ��Ѿ�Ѥ��������أ�





	��������θ��ض������ּ�����ɫ������������Ҫ����ܶ����ɫ�����ֵ�ʱ����FillConsoleOutputAttribute�Ͳ��Ǻð취�ˡ�����취֮һ��������system��������color��ʵ�֣����������Ļ�֮ǰ�������ɫҲ�ᶪʧ���ܲ����м򵥿��ٵİ취�أ�������ɫ����̨��ϵ��֮�ڣ����̻����ڱ���ԭ����ɫ������£��Դ������ɫ���ֵĿ��������


	����Ч�Ľ���취������ʹ��API����SetConsoleTextAttribute��


	BOOL
	SetConsoleTextAttribute(

	HANDLE hConsoleOutput,

	WORD wAttributes

	)


	������⣺


	HANDLE hConsoleOutput��

	����̨������������ϻ�


	WORD wAttributes��

	��ɫ���ԣ�����ο�ϵ������֮�ٵĸ���


	��ôAPIִ�гɹ�֮�����е������printf��cout�ȣ�������������ɫ������������������ݵ�Ӱ�졣


	ʾ�����룺


	HANDLE hOut;

WORD color;

hOut=GetStdHandle(STD_OUTPUT_HANDLE);

color=FOREGROUND_RED|BACKGROUND_GREEN;

SetConsoleTextAttribute(hOut,color);

printf("Hello!");


����ܹ�������ʹ�����API�������ܼ򻯲��ٴ��롣











	������������Ҫ�ĺ�����̨������ɫ����̨��ϵ�е����º����Ѿ������ˡ���������濴�����ѣ����ڵĿ���̨һ������ʰ�쵵İɣ�������ҿ��Կ�����������һ�����ֱ�ɫ������5�д��룬�Ե÷ǳ�ӷ�ף�Ч��Ҳ���ߡ������ṩ����д��3���������ܹ�����������ɫ������Ƶ�Ч�ʡ�


	�ظ�2¥2012-05-31 14:19�ٱ� |
	������ҵ�ٱ�
	������Ϣ�ٱ�

	xiaoboaicyuyan
	���꼶7


	CursorGo��д������


	ͷ�ļ���Windows.h

	���ܣ����Ĺ��λ��

	�÷���CursorGo(x,y);

���壺x,yΪint�ͣ��ֱ���X�����Y����


	void CursorGo(int x,int
	y)

{

	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos={x,y};

	SetConsoleCursorPosition(hOutput,pos);

}


ClearScreen��д������


	ͷ�ļ���Windows.h

	���ܣ�����

	�÷���ClearScreen(NULL);��ClearScreen(wAttributes);

���壺����һΪNULLʱ��ֱ��������ʹ��Ĭ�ϱ���ɫ������һΪ��ɫ����ʱ��������ʹ����ɫ���ԣ�������ΪĬ����ɫ��


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


PrintText��д������


	ͷ�ļ���Windows.h

	���ܣ���ָ�������������ָ����ɫ������

	�÷���PrintText(text,x,y,wAttributes);��PrintText(text,x,y,NULL);

���壺����һΪ�ִ���ָ�룻����������Ϊint�ͣ�ָ�����ꣻ������ΪNULLʱ�����������ΪĬ����ɫ��������Ϊ��ɫ����ʱ�����������Ϊִ����ɫ��������ΪĬ����ɫ��


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








��ɫ�������ɸ������������ɵģ�Ҫ�õ����Ч����ֻ�в��Ȼ���ֹ�ƴ�ն��ɣ�Ч�ʺܵ͡�����д��һ�����ߣ����Կ�����ϳ������Ч��������ϵĹ����п�ֱ��Ԥ��Ч�����ŵ���ϵ�������У�Ҳ��ĥ�����󿳲񹤡�


	����Ԥ����

























	����ǳ����б�ʹ�������������ѡ��


	�ұ���Ԥ��Ч������ֱ�Ӳ鿴��ѡ������ϵ�����Ч��


	�±��ǲ������г�����ѡ������ϵĽ�������԰�Copy���Ƶ������塣��һ����10���ƣ��ڶ�����16���ơ�


	ֱ�����������ɡ�


	���⣬�˹�����CMD��ֱ�ӵ����޷��������С�*/