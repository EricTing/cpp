#include <iostream>
using namespace std;

template<class T>
T*** allocate3D(unsigned int d1, unsigned int d2, unsigned d3)
{
  T*** val_ptr = new T**[d1];
  for (int i = 0; i < d1; i++) {
    val_ptr[i] = new T*[d2];
    for (int j = 0; j < d2; j++) {
      val_ptr[i][j] = new T[d3];
    }
  }

  return val_ptr;
}

template<class T>
void dellocate(T*** val_ptr, unsigned int d1, unsigned int d2)
{
  if(val_ptr) {
    for (int i = 0; i < d1; i++) {
      for (int j = 0; j < d2; j++) {
        delete[] val_ptr[i][j];
      }
      delete[] val_ptr[i];
    }
  }
}


template<class T>
class CArray3D
{
private:
  T*** val;
  unsigned int d1;
  unsigned int d2;
  unsigned int d3;

public:
  CArray3D():
    val{NULL}, d1{0}, d2{0}, d3{0} {}
  CArray3D(unsigned int d1_, unsigned int d2_, unsigned int d3_);

  T** operator[](int i) {
    if(val == NULL) {
      return NULL;
    }
    else
      return val[i];
  }

  virtual ~CArray3D();
};

template<class T>
CArray3D<T>::CArray3D(unsigned int d1_, unsigned int d2_, unsigned int d3_)
{
  d1 = d1_;
  d2 = d2_;
  d3 = d3_;
  val = allocate3D<T>(d1_, d2_, d3_);
}

template<class T>
CArray3D<T>::~CArray3D()
{
  dellocate<T>(val, d1, d2);
}

int main()
{
  CArray3D<int> a(3,4,5);
  int No = 0;
  for( int i = 0; i < 3; ++ i )
    for( int j = 0; j < 4; ++j )
      for( int k = 0; k < 5; ++k )
        a[i][j][k] = No ++;
  for( int i = 0; i < 3; ++ i )
    for( int j = 0; j < 4; ++j )
      for( int k = 0; k < 5; ++k )
        cout << a[i][j][k] << ",";

  return 0;
}
