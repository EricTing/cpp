// 在类定义中，前面有virtual关键字的成员函数就是虚函数
// constructor 和 静态成员函数不能是虚函数
// 派生类指针可以赋值给基类指针
// 通过基类指针调用基类和派生类中的同名虚函数时：
// 1. 若该指针指向一个基类的对象，那么调用的是基类的虚函数
// 2. 若该指针指向一个派生类的对象，那么调用的是派生类的虚函数

#include <iostream>

using namespace std;

class A {
private:
  int nVal;
public:
  void Fun()
  { cout << "A::Fun" << endl; }
  void Do()
  { cout << "A::Do" << endl; }
};

class B:public A {
public:
  virtual void Do()
  { cout << "B::Do" << endl; }
};

class C:public B {
public:
  void Do( )
  { cout << "C::Do" <<endl; }
  void Fun()
  { cout << "C::Fun" << endl; }
};

void Call(B& p)
{
  p.Fun();  p.Do();
}
int main()  {
  C c;    Call(c);
  return 0;
}
