#if false // mini ��ŷ�ý��� ����� 

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//������ ���¼�, �̸� �ִ���ڼ�, acc���� ��������� �迭
int createCnt = 0;
const int maxNameLength = 20;

void showMenu(void);      //�޴����
void createBankNo(void);  //���°���
void depositMoney(void);  //�Ա�
void withdrawMoney(void); //���
void selectedAcc(void);   //���� ���� ��ȸ
void showAllAcc(void);    //��ü ���� ��ȸ
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
			cout << "���� �Է� �Ұ�" << endl;
			return;
		}

		if (haveMoney < money)
		{
			cout << "��ݾ� ����" << endl;
			return;
		}

		haveMoney -= money;
		cout << "��� �Ϸ�" << endl;
	}

	void ShowAccInfo()
	{
		cout << "���� ID : " << accId << endl;
		cout << "�� �� : " << custName << endl;
		cout << "�� �� : " << haveMoney << endl;
	}

	int SelectAccInfo(int selectedId)
	{
		for (int i = 0; i < createCnt; i++)
		{
			if ( accId == selectedId)
			{
				cout << "�����ݾ� = " << haveMoney << endl;

				return haveMoney;
			}
		}

		cout << "��ȸ����" << endl;
		return 0;
	}

	~Account()
	{
		delete[] custName;
		cout << "������������ delete " << endl;
	}
};

Account* accArr[100];

int main(void)
{
	int selectCount = NULL;

	showMenu();
	cout << "���� : "; cin >> selectCount; cout << endl;;

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
	cout << "[���θ޴�]" << endl;
	cout << "1. ���»���" << endl;
	cout << "2. �Ա��ϱ�" << endl;
	cout << "3. ����ϱ�" << endl;
	cout << "4. ���� ��ȸ" << endl;
	cout << "5. ��� ���� ��ȸ" << endl;
	cout << "6. ����" << endl;

	cout << "\r\r\n\n" << endl;
	return;
}

void createBankNo(void)
{
	int accId;
	char name[maxNameLength];
	int haveMoney = 0;

	cout << "[���»���]" << endl;
	cout << "1. ������ ���¹�ȣ�� �Է��� �ּ��� : ";
	cin >> accId;
	cout << "2. �̸� : ";
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

	cout << "[�Ա��ϱ�]" << endl;
	cout << "1. �Ա��� ���� : " << endl;
	cin >> accId;
	cout << "2. �Ա� �ݾ� : " << endl;
	cin >> money;

	if (money < 0)
	{
		cout << "���� �Է� �Ұ�" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i] -> GetAccId() == accId)
		{
			accArr[i] -> Deposit(money);
			cout << "�Ա��� �Ϸ�Ǿ����ϴ�" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
	}

	cout << "��ȿ�� ���¹�ȣ�� ��� �Ա� �Ұ�" << endl;

	cout << "\r\r\n\n" << endl;
	main();
}

void withdrawMoney(void)
{
	int accId;
	int money;

	cout << "[����ϱ�]" << endl;
	cout << "1. ����� ���� : " << endl;
	cin >> accId;
	cout << "2. ��� �ݾ� : " << endl;
	cin >> money;

	if (money < 0 )
	{
		cout << "���� �Է� �Ұ�" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i] -> SelectAccInfo(i) < money)
		{
			cout << "��ݾ��� �����׺��� ���Ƽ� ��� �Ұ�" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
		if (accArr[i] -> GetAccId() == accId)
		{
			accArr[i] -> Withdraw(money);
			cout << "���� �Ϸ�Ǿ����ϴ�" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
	}

	cout << "��ȿ�� ���¹�ȣ�� ��� �Ա� �Ұ�" << endl;

	cout << "\r\r\n\n" << endl;
	main();
}

void selectedAcc(void)
{
	int accId;
	cout << "[������ȸ �ϱ�]" << endl;
	cout << "1. ��ȸ�� ���� : " << endl;
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

	cout << " ��ȸ����;; " << endl;

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