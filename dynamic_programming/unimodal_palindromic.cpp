#include <iostream>
#include <vector>

using namespace std;

/**
 *   \file unimodal_palindromic.cpp
 *   \brief number of Unimodal Palindromic Decompositions of the input value
 *
 *  method:
 *  input value is x, number of Unimodal Palindromic Decompositions is U[x]
 *  U[x] = 1 + P[x][i],
 *  P[x][i] is the number of Unimodal Palindromic Decompositions of x with the value at the end not less than i, 2 * i <= x
 *  so the solution is P[x][1] + 1
 *  if 2 * i = x
 *  P[x][i] = 1 + P[x][i + 1]
 *  else if there exists a y >= i, and i * 2 + y == x
 *  then P[x][i] = 1 + P[y][i] + P[x][i + 1]
 *  else
 *  P[x][i] = P[x][i + 1]

 *  Boundary conditions:
 *  P[1][1] = 0
 */

int NumDecomposition(int n)
{
  vector<vector<int> > P;
  for (int i = 0; i < n + 1; i++) {
    vector<int> v(n + 1, 0);
    P.push_back(v);
  }

  P[1][1] = 0;

  for(int x = 2; x <= n; x++) {
    for(int i = (x + 1) / 2; i >= 1; i--) {
      bool tt = false;
      if ((2 * i) == x) {
        P[x][i] = 1 + P[x][i + 1];
        tt = true;
      }
      else {
        for (int y = i; 2 * i + y <= x; y++) {
          if (2 * i + y == x) {
            P[x][i] = 1 + P[y][i] + P[x][i + 1];
            tt = true;
          }
        }
      }

      if (tt == false)
        P[x][i] = P[x][i + 1];
    }
  }

  return P[n][1] + 1;
}

int main()
{

  for(int i = 2; i < 9; i++)
    std::cout << i << " " << NumDecomposition(i) << std::endl;

  cout << NumDecomposition(92) << endl;

  return 0;
}
