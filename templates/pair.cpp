#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Pair
{
public:
  T1 key;
  T2 val;
  Pair(T1 k, T2 v): key(k), val(v){};
  bool operator<(const Pair<T1, T2>& p) const;
  virtual ~Pair(){};
};

template<class T, int size>
class Name
{
  T array[size];
};

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2>& p) const
{
  return key < p.key;
}

int main(int argc, char *argv[])
{
  Pair<string, int> student("Tom", 9);
  cout << student.key << " " << student.val;

  Name<double, 40> a2;

  return 0;
}

