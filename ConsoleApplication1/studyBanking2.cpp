#if false // mini 뱅킹시스템 만들기 

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//생성된 계좌수, 이름 최대글자수, acc생성 정보저장된 배열
int createCnt = 0;
const int maxNameLength = 20;

void showMenu(void);      //메뉴출력
void createBankNo(void);  //계좌개설
void depositMoney(void);  //입금
void withdrawMoney(void); //출금
void selectedAcc(void);   //선택 계좌 조회
void showAllAcc(void);    //전체 계좌 조회
void exit(void);

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWMONDEY, SHOWALLACC, EXIT };

class Account
{
private:
	int accId;
	char* custName;
	int haveMoney;
public:
	Account(int id, char* name, int money)
		: accId(id), haveMoney(money)
	{
		custName = new char[strlen(name) + 1];
		strcpy(custName, name);
	}

	int GetAccId()
	{
		return accId;
	}

	void Deposit(int money)
	{
		haveMoney += money;
	}

	void Withdraw(int money)
	{
		if (money < 0)
		{
			cout << "음수 입력 불가" << endl;
			return;
		}

		if (haveMoney < money)
		{
			cout << "출금액 부족" << endl;
			return;
		}

		haveMoney -= money;
		cout << "출금 완료" << endl;
	}

	void ShowAccInfo()
	{
		cout << "계좌 ID : " << accId << endl;
		cout << "이 름 : " << custName << endl;
		cout << "잔 액 : " << haveMoney << endl;
	}

	int SelectAccInfo(int selectedId)
	{
		for (int i = 0; i < createCnt; i++)
		{
			if ( accId == selectedId)
			{
				cout << "보유금액 = " << haveMoney << endl;

				return haveMoney;
			}
		}

		cout << "조회에러" << endl;
		return 0;
	}

	~Account()
	{
		delete[] custName;
		cout << "삭제삭제삭제 delete " << endl;
	}
};

Account* accArr[100];

int main(void)
{
	int selectCount = NULL;

	showMenu();
	cout << "선택 : "; cin >> selectCount; cout << endl;;

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
		for (int i = 0; i < createCnt; i++)
			delete accArr[i];
		exit();
	default:
		cout << "errrrrrrrr" << endl;
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

	accArr[createCnt] = new Account(accId, name, haveMoney);

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
		if (accArr[i] -> GetAccId() == accId)
		{
			accArr[i] -> Deposit(money);
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

	if (money < 0 )
	{
		cout << "음수 입력 불가" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i] -> SelectAccInfo(i) < money)
		{
			cout << "출금액이 보유액보다 많아서 출금 불가" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
		if (accArr[i] -> GetAccId() == accId)
		{
			accArr[i] -> Withdraw(money);
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
		if (accArr[i] -> GetAccId() == accId)
		{
			accArr[i] -> SelectAccInfo(accId);

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
		accArr[i]-> ShowAccInfo();
	}

	cout << "\r\r\n\n" << endl;
	main();
}

void exit(void)
{
	return;
}

#endif