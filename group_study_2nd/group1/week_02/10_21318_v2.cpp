/*
https://www.acmicpc.net/problem/21318 : 피아노 체조
누적합 풀이
3968KB 44ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5) // 100,000
#define endl '\n'
int N, Q;
int num[MAXN + 10], mist[MAXN + 10];
int X[MAXN + 10], Y[MAXN + 10];
int psum[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> num[i];
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> X[i] >> Y[i];
}
void Solve() {
  // num 마지막에 가장 큰 수 추가, mist[N] 비교를 편하게.
  num[N + 1] = ((int)2e9);
  // 실수 여부 체크하여 mist[i]에 저장
  for (int i = 1; i <= N; i++) if (num[i] > num[i + 1]) mist[i] = 1;
  // mist를 기준으로 psum 구하기
  for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + mist[i];
  // 실수 누적합
  for (int i = 1; i <= Q; i++) {
    int ret = psum[Y[i]] - psum[X[i] - 1];
    // 마지막에는 실수를 하지 않으므로 고려해야 함
    if (mist[Y[i]] == 1) ret--;
    cout << ret << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
