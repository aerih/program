#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "股东编号：" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t工作职责是：让狗腿子办事" << endl;
}

//获取职工岗位名称
string Boss::getDeptName()
{
	return string("老板");
}