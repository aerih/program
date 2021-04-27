#include "manager.h"


Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "员工编号：" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t工作职责是：监督搬砖" << endl;
}

//获取职工岗位名称
string Manager::getDeptName()
{
	return string("经理");
}