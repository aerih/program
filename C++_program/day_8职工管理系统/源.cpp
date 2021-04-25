#include "workerManager.h"
#include "Worker.h"
#include "employee.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"


int main()
{
	int flag = 0;
	WorkerManager wm;
	while (true)
	{
		wm.showMenu();
		cin >> flag;
		switch (flag)
		{
		case 0://退出系统
			wm.exitSystem();
			return 0;
			break;
		case 1://添加员工
			wm.addEmp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.del_Emp();
			break;
		case 4:
			wm.mod_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "请输入规定数字" << endl;
			break;
		}
		system("cls");
	}
	
	system("pause");
	return 0;
	
}