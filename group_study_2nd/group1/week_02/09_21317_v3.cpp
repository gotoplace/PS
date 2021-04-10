/*
https://www.acmicpc.net/problem/21317 : 징검다리 건너기
브루트포스 비트마스킹
2016KB 60ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N, K;
int S[20 + 2][2 + 2];
int sel[20 + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) cin >> S[i][0] >> S[i][1];
  cin >> K;
}
int Calc(int size) {
  // 1번 돌과 N번 돌이 없으면 무효처리
  if (sel[0] != 0 || sel[size - 1] != N - 1) return INT_MAX;
  int cnt3 = 0;
  for (int i = 0; i < size - 1; i++) {
    // 돌 간격이 3보다 크면 무효처리
    if (sel[i + 1] - sel[i] > 3) return INT_MAX;
    if (sel[i + 1] - sel[i] == 3) cnt3++;
    // 돌 간격이 3인 상황이 1보다 크면 무효처리
    if (cnt3 > 1) return INT_MAX;
  }
  // 유효한 조합이니, 에너지 합을 계산하자.
  int ret = 0;
  for (int i = 0; i < size - 1; i++) {
    if (sel[i + 1] - sel[i] == 1) ret += S[sel[i]][0];
    else if (sel[i + 1] - sel[i] == 2) ret += S[sel[i]][1];
    else ret += K;
  }
  return ret;
}
int Solve() {
  int ans = INT_MAX, max = 1 << N;
  for (int i = 1; i < max; i++) {
    int idx = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) sel[idx++] = j;
    }
    ans = min(ans, Calc(idx));
  }
  return ans;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
