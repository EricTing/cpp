#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int minArea = 1 << 30;
int area = 0;
int minV[30];
int minA[30];

void Dfs(int v, int n, int r, int h);

int main() {
  cin >> N >> M; // M levels and Volumn N
  minV[0] = 0;
  minA[0] = 0;
  for (int i = 0; i <= M; i++) {
    minV[i] = minV[i - 1] + i * i * i;
    minA[i] = minA[i - 1] + 2 * i * i;
  }

  if (minV[M] > N) {
    cout << 0 << endl;
  } else {
    int maxH = (N - minV[M-1]) / (M * M) + 1;
    int maxR = sqrt(double(N - minV[M - 1]) / M) + 1;
    area = 0;
    minArea = 1 << 30;
    Dfs(N, M, maxR, maxH);
    if (minArea == 1 << 30)
      cout << 0 << endl;
    else
      cout << minArea << endl;
  }

  return 0;
}


int MaxVforNRH(int n, int r, int h) {
  int v = 0;
  for (int i = 0; i < n; i++) {
    v += (r - i) * (r - i) * (h - i);
  }
  return v;
}


void Dfs(int v, int n, int r, int h) {
  if (n == 0) {
    if (v) return;
    else {
      minArea = min(minArea, area);
      return;
    }
  }
  if (v <= 0) {
    return;
  }
  if (minV[n] > v) {
    return;
  }
  if (area + minA[n] >= minArea) {
    return;
  }
  if (h < n || r < n) {
    return;
  }

  if (MaxVforNRH(n, r, h) < v) {
    return;
  }

  for (int rr = r; rr >= n; rr--) {
    if (n == M)
      area = rr * rr;
    for (int hh = h; hh >= n; hh--) {
      area += 2 * rr * hh;
      Dfs(v - rr * rr * hh,
          n - 1,
          rr - 1,
          hh - 1);
      area -= 2 * rr * hh;
    }
  }
}
