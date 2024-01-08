#if false // mini ��ŷ�ý��� ����� 

#include <iostream>
#include <cstring>

using namespace std;

//������ ���¼�, �̸� �ִ���ڼ�, acc���� ��������� �迭
int createCnt = 0;
const int maxNameLength = 20;

void showMenu(void);      //�޴����
void createBankNo(void);  //���°���
void depositMoney(void);  //�Ա�
void withdrawMoney(void); //���
void selectedAcc(void);   //���� ���� ��ȸ
void showAllAcc(void);   //��ü ���� ��ȸ
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
	cout << "���� : "; cin >> selectCount;

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
		if (accArr[i].accID == accId) 
		{
			accArr[i].haveMoney += money;
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

	if (money < 0)
	{
		cout << "���� �Է� �Ұ�" << endl;

		cout << "\r\r\n\n" << endl;
		main();
		return;
	}

	for (int i = 0; i < createCnt; i++)
	{
		if (accArr[i].haveMoney < money) 
		{
			cout << "��ݾ��� �����׺��� ���Ƽ� ��� �Ұ�" << endl;

			cout << "\r\r\n\n" << endl;
			main();
			return;
		}
		if (accArr[i].accID == accId)
		{
			accArr[i].haveMoney -= money;
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
		if (accArr[i].accID == accId)
		{
			cout << "�����ݾ� = " << accArr[i].haveMoney << endl;

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
		cout << "���¹�ȣ = " << accArr[i].accID << endl;
		cout << "�����ݾ� = " << accArr[i].haveMoney << endl;
		cout << "�̸� = " << accArr[i].custName << endl;
	}

	cout << "\r\r\n\n" << endl;
	main();
}

void exit(void) 
{
	return;
}

#endif