/*
https://www.acmicpc.net/problem/1182 : 부분수열의 합

DFS 풀이 v1
2016KB 8ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, S, sol;
int sel[20 + 2], num[20 + 2];
int dbg = 0;
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> num[i];
}
void DFS(int cnt, int s, int sum) {
  if (dbg) cout << "  cnt: " << cnt << ", s: " << s << ", sum: " << sum << endl;
  if (sum == S && cnt > 0) sol++;
  if (cnt == N) return;
  for (int i = s; i < N; i++) {
    if (sel[i] == 1) continue;
    sel[i] = 1;
    DFS(cnt + 1, i, sum + num[i]);
    sel[i] = 0;
  }
}
int Solve() {
  DFS(0, 0, 0); // 최초 sum이 0부터 시작
  return sol;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
