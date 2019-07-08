#include <iostream>

using namespace std;

class Box {
private:
	double length;
	double height;
	double width;
public:
	Box(void){}
	Box(double length, double height, double width)
	{
		this->length = length;
		this->height = height;
		this->width = width;
	}
	double getVolume(void)
	{
		return length * height * width;
	}
	void setLength(double length)
	{
		this->length = length;
	}
	void setHeight(double height)
	{
		this->height = height;
	}
	void setWidth(double width)
	{
		this->width = width;
	}
	double getLength()
	{
		return this->length;
	}
	double getHeight()
	{
		return this->height;
	}
	double getWidth()
	{
		return this->width;
	}
	Box operator+(const Box& b)
	{
		Box box;
		box.length = this->length + b.length;
		box.height = this->height + b.height;
		box.width = this->width + b.width;
		return box;
	}
};

int main()
{
	Box box1(2.0, 3.0, 4.0);
	Box box2(5.0, 6.0, 7.0);
	Box box3;

	cout << "volume of box1: " << box1.getVolume() << endl;
	cout << "volume of box2: " << box2.getVolume() << endl;
	
	box3 = box1 + box2;
	cout << "box3.length = " << box3.getLength() << endl;
	cout << "box3.height = " << box3.getHeight() << endl;
	cout << "box3.width = " << box3.getWidth() << endl;
	cout << "volume of box3: " << box3.getVolume() << endl;

	return 0;
}
