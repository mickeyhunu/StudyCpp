#if false // mini 뱅킹시스템 만들기 

#include <iostream>
#include <cstring>

using namespace std;

//생성된 계좌수, 이름 최대글자수, acc생성 정보저장된 배열
int createCnt = 0;
const int maxNameLength = 20;

void showMenu(void);      //메뉴출력
void createBankNo(void);  //계좌개설
void depositMoney(void);  //입금
void withdrawMoney(void); //출금
void selectedAcc(void);   //선택 계좌 조회
void showAllAcc(void);   //전체 계좌 조회
void exit(void);

enum {CREATE = 1, DEPOSIT, WITHDRAW, SHOWMONDEY, SHOWALLACC, EXIT};

typedef struct 
{
	int accID;
	char custName[maxNameLength];
	int haveMoney;
}Account;

Account accArr[100];


int main(void) 
{
	int selectCount = NULL;
	
	showMenu();
	cout << "선택 : "; cin >> selectCount;

	switch (selectCount)
	{
	case CREATE:
		createBankNo();
		break;
	case DEPOSIT:
		depositMoney();
		break;
	case WITHDRAW:
		withdrawMoney();
		break;
	case SHOWMONDEY:
		selectedAcc();
		break;
	case SHOWALLACC:
		showAllAcc();
		break;
	case EXIT:
		exit();
	default:
		cout << "default" << endl;
	}
}

void showMenu(void)
{
	cout << "[메인메뉴]" << endl;
	cout << "1. 계좌생성" << endl;
	cout << "2. 입금하기" << endl;
	cout << "3. 출금하기" << endl;
	cout << "4. 계좌 조회" << endl;
	cout << "5. 모든 계좌 조회" << endl;
	cout << "6. 종료" << endl;

	cout << "\r\r\n\n" << endl;
	return;
}

void createBankNo(void)
{
	int accId;
	char name[maxNameLength];
	int haveMoney = 0;

	cout << "[계좌생성]" << endl;
	cout << "1. 생성할 계좌번호를 입력해 주세요 : "; 
	cin >> accId;
	cout << "2. 이름 : ";
	cin >> name;

	accArr[createCnt].accID = accId;
	strcpy_s(accArr[createCnt].custName, name);
	accArr[createCnt].haveMoney = haveMoney;

	createCnt++;

	cout << "\r\r\n\n" << endl;
	main();
}

void depositMoney(void)
{
	int accId;
	int money;

	cout << "[입금하기]" << endl;
	cout << "1. 입금할 계좌 : " << endl;
	cin >> accId;
	cout << "2. 입금 금액 : " << endl;
	cin >> money;

	if (money < 0) 
	{
		cout << "음수 입력 불가" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++) 
	{
		if (accArr[i].accID == accId) 
		{
			accArr[i].haveMoney += money;
			cout << "입금이 완료되었습니다" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
	}

	cout << "유효한 계좌번호가 없어서 입금 불가" << endl;

	cout << "\r\r\n\n" << endl;
	main();
}

void withdrawMoney(void)
{
	int accId;
	int money;

	cout << "[출금하기]" << endl;
	cout << "1. 출금할 계좌 : " << endl;
	cin >> accId;
	cout << "2. 출금 금액 : " << endl;
	cin >> money;

	if (money < 0)
	{
		cout << "음수 입력 불가" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i].haveMoney < money) 
		{
			cout << "출금액이 보유액보다 많아서 출금 불가" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
		if (accArr[i].accID == accId)
		{
			accArr[i].haveMoney -= money;
			cout << "출이 완료되었습니다" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
	}

	cout << "유효한 계좌번호가 없어서 입금 불가" << endl;

	cout << "\r\r\n\n" << endl;
	main();
}

void selectedAcc(void)
{
	int accId;
	cout << "[계좌조회 하기]" << endl;
	cout << "1. 조회할 계좌 : " << endl;
	cin >> accId;


	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i].accID == accId)
		{
			cout << "보유금액 = " << accArr[i].haveMoney << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
	}

	cout << " 조회에러;; " << endl;

	cout << "\r\r\n\n" << endl;
	main();
}

void showAllAcc(void)
{
	for (int i = 0; i < createCnt; i++)
	{
		cout << "계좌번호 = " << accArr[i].accID << endl;
		cout << "보유금액 = " << accArr[i].haveMoney << endl;
		cout << "이름 = " << accArr[i].custName << endl;
	}

	cout << "\r\r\n\n" << endl;
	main();
}

void exit(void) 
{
	return;
}

#endif