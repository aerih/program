#include <iostream>
using namespace std;

int q = 0;
void showMainMenu()
{
	cout << "1、添联系人" << endl;
	cout << "2、显联系人" << endl;
	cout << "3、删联系人" << endl;
	cout << "4、查联系人" << endl;
	cout << "5、修联系人" << endl;
	cout << "6、清联系人" << endl;
	cout << "0、退出" << endl;
}

void selet()
{
	int flag = 0;
	cin >> flag;
	
	switch (flag)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

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
	while(1)
	{ 
		showMainMenu();
		selet();
		if (q == 1) break;
	}

	system("pause");
	return 0;
}