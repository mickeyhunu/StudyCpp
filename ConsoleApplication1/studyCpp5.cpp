#if false // call by value, call by reference

#include <iostream>

using namespace std;

int main(void)
{
	int a = 10;
	int* p = &a;

	cout << "a : " << a << endl; // a�� �Ҵ�� 10
	cout << "&a : " << &a << endl; // a�� �Ҵ�� �޸� 0x000
	cout << "p : " << p << endl; // a�� �Ҵ�� �޸�
	cout << "*p : " << *p << endl; // a�� �Ҵ�� �޸��� �� = 10
	cout << "&p : " << &p << endl; //p�� �Ҵ�� �޸� 0x001   * ���� ����� p�̱� ������ �޸� ��ġ�� a�� ��ġ�� �ٸ�
}

#endif