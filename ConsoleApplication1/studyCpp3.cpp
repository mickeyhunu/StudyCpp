// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#if false //오버로드학습 + using + namespace

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