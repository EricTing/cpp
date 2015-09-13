#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

int** allocate2D(int nrow, int ncol)
{
  int** val_ptr = new int*[nrow];
  for (int i = 0; i < nrow; i++) {
    val_ptr[i] = new int[ncol];
  }
  return val_ptr;
}

void dellocate(int** val_ptr, int nrow)
{
  if (val_ptr) {
    for (int i = 0; i < nrow; i++) {
      delete[] val_ptr[i];
    }
    delete[] val_ptr;
  }
}

void copy2D(int** to, int** from, int nrow, int ncol)
{
  for (int i = 0; i < nrow; i++) {
    memcpy(to[i], from[i], sizeof(int) * ncol);
  }
}


class Array2
{
  int** val_ptr;
  int nrow, ncol;
public:
  Array2() {
    val_ptr = NULL;
    nrow = 0;
    ncol = 0;
  }

  Array2(int nrow_, int ncol_) {
    nrow = nrow_;
    ncol = ncol_;
    val_ptr = allocate2D(nrow, ncol);
  }

  ~Array2() {
    dellocate(val_ptr, nrow);
  }

  Array2(const Array2& arr);
  Array2& operator=(const Array2& arr);
  int* operator[](int i);
  int operator()(int i, int j);
};

Array2::Array2(const Array2& arr)
{
  if(!arr.val_ptr) {
    val_ptr = NULL;
    nrow = 0;
    ncol = 0;
    return;
  }
  val_ptr = allocate2D(arr.nrow, arr.ncol);
  nrow = arr.nrow;
  ncol = arr.ncol;
}

Array2& Array2::operator=(const Array2& arr)
{
  if (val_ptr == arr.val_ptr)
    return *this;
  if (arr.val_ptr == NULL ) {
    dellocate(val_ptr, nrow);
    val_ptr = NULL;
    nrow = 0;
    ncol = 0;
    return *this;
  }

  if ((nrow != arr.nrow) || (ncol != arr.ncol)) {
    dellocate(val_ptr, nrow);
    val_ptr = allocate2D(arr.nrow, arr.ncol);
  }

  copy2D(val_ptr, arr.val_ptr, arr.nrow, arr.ncol);
  nrow = arr.nrow;
  ncol = arr.ncol;

  return *this;
}

int* Array2::operator[](int n)
{
  if ((val_ptr) && (n < nrow)) {
    return val_ptr[n];
  }
  else {
    throw range_error("out of range in []");
  }
}

int Array2::operator()(int i, int j)
{
  if ((val_ptr) && (i < nrow) && (j < ncol)) {
    return val_ptr[i][j];
  }
  else
    throw range_error("out of range");
}



int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
