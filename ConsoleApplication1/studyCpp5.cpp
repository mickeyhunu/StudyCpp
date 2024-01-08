#if false // call by value, call by reference

#include <iostream>

using namespace std;

int main(void)
{
	int a = 10;
	int* p = &a;

	cout << "a : " << a << endl; // a에 할당된 10
	cout << "&a : " << &a << endl; // a가 할당된 메모리 0x000
	cout << "p : " << p << endl; // a가 할당된 메모리
	cout << "*p : " << *p << endl; // a가 할당된 메모리의 값 = 10
	cout << "&p : " << &p << endl; //p가 할당된 메모리 0x001   * 새로 선언된 p이기 때문에 메모리 위치는 a의 위치와 다름
}

#endif