#include <iostream>
using namespace std;

class Cbox
{
public:
	double length;
	double breadth;
	double height;
	
public:
	double get(void)
	{
		return length * breadth * height;
	}
	void set()
	{
		cout << "please enter the box's length breadth height" << endl;
		double len, bre, hei;
		cin >> len >> bre >> hei;
		length = len;
		breadth = bre;
		height = hei;
	}
};



void test()
{
	double volume = 0.0;
	Cbox box;
	cin >> box.length >> box.breadth >> box.height;
	volume = box.length * box.breadth * box.height;
	cout << "the box volume is :" << volume << endl;

}

void test_1()
{
	double volume = 0.0;
	Cbox box1;
	box1.set();
	volume = box1.get();
	cout << "the box volume is : " << volume << endl;
}

int main()
{
	test_1();
	system("pause");
	return 0;
}