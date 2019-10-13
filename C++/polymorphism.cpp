#include <iostream>

using namespace std;

class Shape
{
protected:
    double width;
    double height;

public:
    Shape(double width, double height)
    {
        this->width = width;
        this->height = height;
    }
    // 加上virtual，代表该函数是一个虚函数，函数绑定的对象在运行时被调用时才能确定
    // 也叫后期绑定或者动态链接
    /* virtual double area() = 0; 这种形式的叫纯虚函数，= 0 代表该函数没有方法体*/
    // 纯虚函数我理解为Java中的抽象方法，没有方法体
    virtual double area()
    {
        cout << "Parent class area." << endl;
        return (width * height);
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : Shape(width, height) {}
    double area()
    {
        cout << "Rectangle class area." << endl;
        return (width * height);
    }
};

class Square : public Shape
{
public:
    Square(double len) : Shape(len, len) {}
    double area()
    {
        cout << "Square class area." << endl;
        return (width * height);
    }
};

int main(int argc, char *argv[])
{
    Shape *sp;
    Rectangle rect(3.0, 4.0);
    Square sq(6.0);

    sp = &rect;
    sp->area();

    sp = &sq;
    sp->area();
}