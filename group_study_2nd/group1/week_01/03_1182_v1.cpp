/*
https://www.acmicpc.net/problem/1182 : 부분수열의 합

참고 : https://mm5-gnap.tistory.com/304, https://instories.tistory.com/76?category=878872

DFS대신 Bitmasking으로 풀이
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N, S;
int num[20 + 2];
int dbg = 0;
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }
}
int Solve() {
  int cnt = 0; // 부분 수열 중 그 수열의 원소를 더한 값이 S가 되는 경우의 수
  int max = (1 << N);
  if (dbg) cout << "  max: " << endl;
  for (int i = 1; i < max; i++) {
    int sum = 0;
    for (int k = 0; k < N; k++) {
      if (i & (1 << k)) {
        sum += num[k];
        if (dbg) cout << "    i: " << i << ", 1 << k: " << (1 << k) << ", sum: " << sum << endl;
      }
    }
    if (dbg) cout << endl;
    if (sum == S) cnt++;
  }
  return cnt;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
