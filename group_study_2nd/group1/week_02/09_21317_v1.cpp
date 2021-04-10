/*
https://www.acmicpc.net/problem/21317 : 징검다리 건너기
DP top-down 방식으로 접근.
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N, K, mincost = INT_MAX;
int S[20 + 2][2 + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i < N; i++) cin >> S[i][0] >> S[i][1];
  cin >> K;
}
void DFS(int idx, int used, int sum) {
  if (idx == N) { // 마지막 돌에 도달한 경우 mincost 갱신
    mincost = min(mincost, sum); return;
  }
  if (idx + 1 <= N) DFS(idx + 1, used, sum + S[idx][0]); // 작은 점프할 경우 N보다 작거나 같다면 재귀호출
  if (idx + 2 <= N) DFS(idx + 2, used, sum + S[idx][1]); // 큰점프할 경우 N보다 작거나 같다면 재귀호출
  if (idx + 3 <= N && used == 0) DFS(idx + 3, 1, sum + K); // 매우큰점프 할 경우 N보다 작거나 같다면 재귀호출
}
void Solve() {
  DFS(1, 0, 0);
  cout << mincost << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
