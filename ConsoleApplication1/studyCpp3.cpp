// ConsoleApplication1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#if false //�����ε��н� + using + namespace

#include <iostream>

using namespace std;

namespace human 
{
	void SimpleFunc(void)
	{
		cout << "human namespace" << endl;
	}
}

namespace animal
{
	void SimpleFunc(void)
	{
		cout << "animal namespace" << endl;
	}

	namespace dog {
		namespace yoki {
			char dogName[55] = "sarangE";
		}
	}
}

int main()
{
	human::SimpleFunc();
	animal::SimpleFunc();

	cout << animal::dog::yoki::dogName;
	namespace ady = animal::dog::yoki;
	cout << ady::dogName;
}

#endif