/*
https://www.acmicpc.net/problem/11441 : 합 구하기
2796KB 40ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5) // 100,000
#define endl '\n'
int N, M;
int A[MAXN + 10], psum[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
}
void Solve() {
  // psum 구하기
  psum[1] = A[1];
  for (int i = 2; i <= N; i++) psum[i] = psum[i - 1] + A[i];
  cin >> M;
  for (int i = 0; i < M; i++) {
    int j, k;
    cin >> j >> k;
    cout << psum[k] - psum[j - 1] << endl; // j ~ k 구간 합
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
