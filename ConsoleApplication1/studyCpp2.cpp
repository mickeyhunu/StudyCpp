// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#if false //오버로드학습

#include <iostream>

int MyFunc(int num)
{
	num;
	return num;
}

int MyFunc(int a, int b)
{
	return a + b;
}
int main()
{
	MyFunc(20);
	MyFunc(20, 30);
	return 0;
}

#endif