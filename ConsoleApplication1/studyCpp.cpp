// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#if false //입출력 학습

#include <iostream>

int main()
{
    int val1;
    int val2;
    int val3;
    int val4;
    std::cout << "1번째 정수 입력 : ";
    std::cin >> val1;
    std::cout << "2번째 정수 입력 : ";
    std::cin >> val2;             
    std::cout << "3번째 정수 입력 : ";
    std::cin >> val3;             
    std::cout << "4번째 정수 입력 : ";
    std::cin >> val4;


    int result = val1 + val2 + val3 + val4;
    std::cout << "value :" << result << std::endl;

    std::cout << "---------------------------------" << std::endl;

    char number[100];
    std::cout << "번호입력 : ";
    std::cin >> number;

    std::cout << number << std::endl;

    std::cout << "---------------------------------" << std::endl;

    int vava;
    std::cout << "숫자입력 : ";
    std::cin >> vava;

    for (int i = 1; i <= 9; i++) 
    {
        std::cout << vava << " * " << i << " = " << vava * i << std::endl;
    }
}


#endif