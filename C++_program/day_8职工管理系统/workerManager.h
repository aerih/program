#pragma once
#include <iostream>
#include "Worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	void showMenu();
	void exitSystem();
	void addEmp();
	void save();
	void init_Emp();
	void show_Emp();
	void del_Emp();
	void mod_Emp();
	void find_Emp();
	int isExist(int id);
	int m_EmpNum;
	int get_EmpNum();
	Worker** m_EmpArray;
	bool m_FileIsEmpty;


	~WorkerManager();
};