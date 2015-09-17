/**
 *   \file swap.cpp
 *   \brief A Documented file.
 *
 *  1. normal functions are of the highest priority
 *  2. templated functions are of the second highest priority
 *
 */

#include <iostream>

using namespace std;

template<class T>
void Swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template<class T>
T MaxElement(T a[], int size)
{
  T tmpMax = a[0];
  for (int i = 0; i < size; i++) {
    if (tmpMax < a[i]) tmpMax = a[i];
  }
  return tmpMax;
}

int main(int argc, char *argv[])
{
  int a{1}, b{2};
  Swap(a, b);
  cout << a << " " << b << endl;

  int l[]{1, 2, 3, 4, 7, 22, 3};
  cout << MaxElement(l, 7) << endl;

  return 0;
}
