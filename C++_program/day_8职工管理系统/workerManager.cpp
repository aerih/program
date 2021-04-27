#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	this->m_EmpNum = this->get_EmpNum();
	cout << "ְ������Ϊ��" << this->m_EmpNum << endl;
	this->m_EmpArray = new Worker* [this->m_EmpNum];
	init_Emp();

	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ�ţ�" << this->m_EmpArray[i]->m_id
	//		<< "ְ��������" << this->m_EmpArray[i]->m_name
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->m_did << endl;
	//}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
	}
}

void WorkerManager::showMenu()
{
	
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	
}

void WorkerManager::exitSystem()
{
	cout << "��лʹ�ã���ӭ�´ι���" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	cout << "����������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker* [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int d_Selet = 0;
			cout << "�������" << i+1 << "Ա����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1  << "Ա��������"<< endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> d_Selet;
			Worker* worker = NULL;
			switch (d_Selet)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				cout << "���������������" << endl;
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;

			delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			
		}
		this->m_FileIsEmpty = false;
		cout << "���ӳɹ�" << addNum << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;

	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_did << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
	
}

int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;
			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
		
		}
		else
			cout << "�޸�ʧ�ܣ����޴���" << endl;

	}
	system("pause");
	system("sys");
}

void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ�����������" << endl;
		cout << "2������ְ������������" << endl;
		int option = 0;
		cin >> option;
		while (true)
		{
			if (option == 1)
			{
				int id = 0;
				cout << "������Ա�����" << endl;
				cin >> id;
				int index = isExist(id);
				if (index != -1)
				{
					cout << "���ҳɹ�����Ա����Ϣ����" << endl;
					this->m_EmpArray[index]->showInfo();
				}
				else
				{
					cout << "����ʧ��" << endl;
				}
				break;
			}
			else if (option == 2)
			{
				string name;
				cout << "������Ա������" << endl;
				cin >> name;
				bool flag = false;


				break;
			}
			else
			{
				cout << "��������ȷ��ѡ��" << endl;
			}
		}

		system("pause");
		system("cls");
	}
}