#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

void Employee::showInfo()
{
	cout << "员工编号：" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t工作职责是：搬砖" << endl;
}

string Employee::getDeptName()
{
	return string("员工");		//可以直接用员工，这样就是string*的格式
}