/*
https://www.acmicpc.net/problem/21317 : 징검다리 건너기
DP top-down + 메모이제이션 방식으로 풀이
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N, K;
int S[20 + 2][2 + 2];
int dp[20 + 2][2 + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i < N; i++) cin >> S[i][0] >> S[i][1];
  cin >> K;
}
int DFS(int idx, int used) {
  if (idx == N) { // 마지막 돌에 도달한 경우 return 0
    return 0;
  }
  if (dp[idx][used] != -1) return dp[idx][used];
  int ret = INT_MAX;
  if (idx + 1 <= N) ret = min(ret, DFS(idx + 1, used) + S[idx][0]);
  if (idx + 2 <= N) ret = min(ret, DFS(idx + 2, used) + S[idx][1]);
  if (idx + 3 <= N && used == 0) ret = min(ret, DFS(idx + 3, 1) + K);
  dp[idx][used] = ret;
  return ret;
}
int Solve() {
  memset(dp, -1, sizeof(dp));
  return DFS(1, 0);
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
