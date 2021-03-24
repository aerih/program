#include <string>
#include <iostream>

using namespace std;

void test_1();

int main()
{
	test_1();
	system("pause");
	return 0;
}

void test_1()
{
	string line = "hello world£¡";
	getline(line);
}