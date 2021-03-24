#include <iostream>
using namespace std;

//class Line
//{
//public:
//	int getlength(void);
//	Line(int len);
//	Line(const Line& obj);
//	~Line();
//private:
//	int* ptr;
//};
//
//Line::Line(int len)
//{
//	cout << "调用构造函数" << endl;
//	ptr = new int;
//	*ptr = len;
//}
//Line::Line(const Line& obj)
//{
//	cout << "调用拷贝构造函数并为ptr赋值" << endl;
//	ptr = new int;
//	*ptr = *obj.ptr;
//}
//Line::~Line()
//{
//	cout << "释放内存" << endl;
//	delete ptr;
//}
//int Line::getlength(void)
//{
//	return *ptr;
//}
//void display(Line obj) {
//	cout << "line的长度大小" << obj.getlength() << endl;
//}
//int main() {
//	Line line(10);
//	display(line);
//}
int Max(int x, int y)
{
	return (x > y) ? x : y;
}

// 程序的主函数
int main()
{

	cout << "Max (20,10): " << Max(20, 10) << endl;
	cout << "Max (0,200): " << Max(0, 200) << endl;
	cout << "Max (100,1010): " << Max(100, 1010) << endl;
	return 0;
}