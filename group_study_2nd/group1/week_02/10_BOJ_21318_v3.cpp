/*
https://www.acmicpc.net/problem/21318 : 피아노 체조
2796KB 52ms
구간합 구하는 방법 간소화
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN ((int)1e5) // 100,000

int N, Q;
int num[MAXN + 10];
int psum[MAXN + 10];
int dbg = 0;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> num[i];
  cin >> Q;
}
void Solve() {
  // psum[] 구하기
  for (int i = 1; i <= N; i++) { // 조건과는 다르게 i 번째 실수를 i + 1 에 업데이트, 마지막 결과는 따로 처리 불필요
    if (num[i - 1] > num[i]) psum[i] = psum[i - 1] + 1;
    else psum[i] = psum[i - 1];
  }

  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    cout << psum[y] - psum[x] << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
