/*
https://www.acmicpc.net/problem/2470 : 두 용액
2408KB 16ms
투 포인터 풀이
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN ((int)1e5) // 100,000
int P[MAXN + 10];
int N;
int dbg = 0;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
}
void Solve() {
  sort(P, P + N);
  int lo = 0, hi = N - 1, prev_lo = 0, prev_hi = 0, prev_sum = ((int)2e9 + 10);
  while (lo < hi) {
    int sum = P[lo] + P[hi];
    if (dbg) cout << "  " << prev_sum << ", " << sum << ", " << lo << " " << hi << ", " << prev_lo << " " << prev_hi << endl;
    if (abs(prev_sum) > abs(sum)) {
      prev_sum = sum; prev_lo = lo; prev_hi = hi;
    }
    if (sum == 0) break; // 0이면 loop 탈출
    else if (sum < 0) lo++; // sum 양수이면 lo 증가
    else hi--; // sum 음수이면 hi 감소
  }
  cout << P[prev_lo] << " " << P[prev_hi] << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
