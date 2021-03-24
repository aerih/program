#include <iostream>
using namespace std;
#include <String>
#define MAX 1

struct Person
{
	string m_name;
	int m_sex;			//1、男	2、女
	int m_age;
	string m_number;
	string m_addr;
};
struct AddressBook
{
	struct Person personArry[MAX];
	int m_size;
};

int q = 0;
AddressBook new_abs;

void showMainMenu()
{
	
	cout << "*****************" << endl;
	cout << "***1、添联系人***" << endl;
	cout << "***2、显联系人***"  << endl;
	cout << "***3、删联系人***"  << endl;
	cout << "***4、查联系人***"	 << endl;
	cout << "***5、修联系人***"	 << endl;
	cout << "***6、清联系人***"	 << endl;
	cout << "***0、  退出  ***"	<< endl;
	cout << "***           ***" << endl;
	cout << "*****************" << endl;
}

void showPerson(AddressBook * abs)
{
	if (abs->m_size == 0)
		cout << "当前记录为空" << endl;
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名:" << abs->personArry[i].m_name << "\t";
			cout << "年龄:" << abs->personArry[i].m_age << "\t";
			cout << "性别:" << (abs->personArry[i].m_sex == 1 ? "男":"女") << "\t";
			cout << "电话:" << abs->personArry[i].m_number << "\t";
			cout << "住址:" << abs->personArry[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void addPerson(AddressBook* abs)
{
	
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_size].m_name = name;
		//***************************************
		cout << "清输入性别：" << endl;
		cout << " 1--man  2---woman " << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		}
		abs->personArry[abs->m_size].m_sex = sex;
		//************************************
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_size].m_age = age;
		//************************************
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_size].m_number = phone;
		//************************************
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArry[abs->m_size].m_addr = address;
		//************************************
		abs->m_size++;
	}
	
	system("pause");
	system("cls");
}

int isExist(AddressBook abs, string name)
{
	for (int i = 0; i < abs.m_size; i++)
	{
		if (abs.personArry[i].m_name == name)
			return i;
	}
	return -1;
}

void deletPers()
{
	string name;
	cout << "请输入要删除联系人的名字" << endl;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret == -1)
	{
		cout << "联系人为空" << endl;
	}
	//else if (ret = MAX - 1)
	//{
	//	new_abs.m_size--;
	//}
	else
	{
		for (int i = ret; i < new_abs.m_size; i++)
		{
			new_abs.personArry[i] = new_abs.personArry[i + 1];
		}
		cout << "删除成功" << endl;
		new_abs.m_size--;
	}
	system("pause");
	system("cls");
}

void checkPer(AddressBook* abs)
{
	cout << "请输入查找人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->personArry[ret].m_name << "\t";
		cout << "年龄:" << abs->personArry[ret].m_age << "\t";
		cout << "性别:" << (abs->personArry[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "电话:" << abs->personArry[ret].m_number << "\t";
		cout << "住址:" << abs->personArry[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPers(AddressBook *abs)
{
	cout << "请输入要修改的用户名称" << endl;
	string name;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret != -1)
	{
		cout << "找到该联系人" << endl;
		cout << "请输入修改者的姓名：" << endl;
		cin >> name;
		abs->personArry[ret].m_name = name;
		//***************************************
		cout << "清输入修改者的性别：" << endl;
		cout << " 1--man  2---woman " << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		}
		abs->personArry[ret].m_sex = sex;
		//************************************
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArry[ret].m_age = age;
		//************************************
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArry[ret].m_number = phone;
		//************************************
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArry[ret].m_addr = address;
		//************************************
		cout << "修改完成！" << endl;	
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBook * abs)
{
	abs->m_size = 0;
	cout << "通讯簿已完成清空" << endl;
	system("pause");
	system("cls");
}

void checkPersonByNumber(AddressBook* abs)
{
	cout << "请输入此人序号" << endl;
	int ret;
	cin >> ret;
	cout << "姓名:" << abs->personArry[ret].m_name << "\t";
	cout << "年龄:" << abs->personArry[ret].m_age << "\t";
	cout << "性别:" << (abs->personArry[ret].m_sex == 1 ? "男" : "女") << "\t";
	cout << "电话:" << abs->personArry[ret].m_number << "\t";
	cout << "住址:" << abs->personArry[ret].m_addr << endl;
	system("pause");
	system("cls");
}

void selet()
{
	int flag = 0;
	cin >> flag;

	switch (flag)
	{
	case 1:
		addPerson(&new_abs);
		break;
	case 2:
		showPerson(&new_abs);
		break;
	case 3:
		deletPers();
		break;
	case 4:
		checkPer(&new_abs);
		break;
	case 5:
		modifyPers(&new_abs);
		break;
	case 6:
		cleanPerson(&new_abs);
		break;
	case 7:
		checkPersonByNumber(&new_abs);
		break;
	case 0:
		cout << "欢迎下次使用" << endl;
		q = 1;
		break;
	default:
		break;
	}
}


int main()
{
	new_abs.m_size = 0;
	while (true)
	{
		showMainMenu();
		selet();
		if (q == 1) break;
	}

	//system("pause");
	return 0;
}