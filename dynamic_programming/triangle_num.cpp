#include <iostream>
#include <algorithm>

#ifndef MAX
#define MAX 101
#endif

int D[MAX][MAX];
int maxSum[MAX][MAX];
int n;

int MaxSum(int i, int j){
  if (maxSum[i][j] != -1) {
    return maxSum[i][j];
  }
  if (i == n) {
    maxSum[i][j] = D[i][j];
  }
  else {
    int x = MaxSum(i + 1, j);
    int y = MaxSum(i + 1, j + 1);
    maxSum[i][j] = max(x, y) + D[i][j];
  }
}

int main(int argc, char const *argv[]) {
  int i, j;
  cin >> n;
  for (i = 0; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        cint >> D[i][j];
        maxSum[i][j] = -1;
      }
  }

  cout << MaxSum(1, 1) << endl;
  return 0;
}
