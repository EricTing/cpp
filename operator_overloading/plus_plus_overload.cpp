class CDemo
{
  int n;
public:
  CDemo(int v):n{v}{}
  CDemo operator++();
  CDemo operator++(int);
  operator int() {return n;}    // 类型转换运算符，不能写返回值类型
  friend CDemo operator--(CDemo &);
  friend CDemo operator--(CDemo &, int); // 双目，需要添加一个无意义的参数
};

CDemo::operator++() {
  n++;
  return *this;
}

CDemo::operator++(int) {
  CDemo tmp(*this);
  n++;
  return tmp;
}

CDemo operator--(CDemo &d) {
  d.n--;
  return d;
}

CDemo operator--(CDemo &d, int) {
  CDemo tmp(d);                 // trick here
  d.n--;
  return tmp;
}


