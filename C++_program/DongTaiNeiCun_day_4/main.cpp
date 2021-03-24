#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	double* ptr = NULL;
//	if (!(ptr = new double))
//		cout << "error:out of memory" << endl;
//	*ptr = 3456.23;
//	cout << "the vaule of ptr is " << *ptr << endl;
//	return 0;
//}

//class Box
//{
//public:
//	Box() {
//		cout << "调用构造函数" << endl;
//	}
//	~Box() {
//		cout << "调用析构函数" << endl;
//	}
//};
//
//int main()
//{
//	Box* myBoxArray = new Box[4];
//	delete[] myBoxArray;
//	return 0;
//}

//C++模板
//1.自动推导数据类型
//2.可以通过<type>来指定数据类型
//template<typename T>
//void mySwap(T &x, T &y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//template<typename T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//				mySwap(arr[max], arr[j]);
//		}
//	}
//}
//
//template<class T>
//void printArray(T arr[], int len)
//{
//	for (int i = 0;i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test_1()
//{
//	char array[] = "ebcadf";
//	int num = sizeof(array) / sizeof(char);
//	mySort(array,num); 
//	printArray(array, num);
//}
//void test_2()
//{
//	int intArr[] = {1, 3, 5, 2, 4, 7, 6};
//	int num = sizeof(intArr) / sizeof(int);
//	mySort(intArr, num);
//	printArray(intArr, num);
//}
//	
//template<class nameType, class ageType>
//class Person
//{
//public:
//	nameType m_name;
//	ageType m_age;
//	Person(nameType name, ageType age )
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//	void myPrint()
//	{
//		cout << "the person name is " << this->m_name << endl;
//		cout << "the person age is " << this->m_age << endl;
//	}
//};
//
//void test_2()
//{
//	Person<string, int> p("zs", 18);
//	p.myPrint();
//}

//class Person1
//{
//public:
//	void showPerson1()
//	{
//		cout << "pereson1 的成员函数" << endl;
//	}
//};
//
//class Person2
//{
//public:
//	void showPerson2()
//	{
//		cout << "pereson2 的成员函数" << endl;
//	}
//};
//
//template<class T>
//class MyClass
//{
//public:
//	T obj;
//	void func1(){
//		obj.showPerson1();
//	}
//	void func2() {
//		obj.showPerson2();
//	}
//};
//void test01()
//{
//	MyClass<Person1> p;
//	p.func1();
//	//p.func2();
//}
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age) {
		this->m_age = age;
		this->m_name = name;
	}
	void printPerson() {
		cout << "the person name is " << this->m_name << endl;
		cout << "the person age is " << this->m_age << endl;
	}
private:
	T1 m_name;
	T2 m_age;
};

template<class T>
void myPrint(T& m)
{
	m.printPerson();
	cout << "T的数据类型为" << typeid(T).name() << endl;
}

void test01()
{
	Person<string, int> p("ts", 22);
	myPrint(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}