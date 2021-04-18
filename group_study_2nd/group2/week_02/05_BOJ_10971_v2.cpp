/*
https://www.acmicpc.net/problem/10971 : 외판원 순회2
한 노드를 출발하여 모든 노드를 순회하고 시작점으로 돌아오는 최소 비용을 구하는 문제.
백트래킹, DFS 순열로 풀이
시작점을 변경하면서 최적의 비용을 구한다.
시간복잡도를 줄이기 위해, 가지치기 필요.
가지치기 조건문 일부 수정, 결과는 동일함
2016KB 8ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N, W[10 + 2][10 + 2];
int visited[10 + 2]; // 노드 방문 체크 배열
int mincost = INT_MAX;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> W[i][j];
}
void DFS(int cnt, int start, int x, int sum) {
  if (cnt == N && start == x) { // 모든 노드를 방문하고 시작점으로 돌아온 경우
    if (mincost > sum) mincost = sum;
    return;
  }
  for (int y = 1; y <= N; y++) {
    if (W[x][y] == 0) continue;
    if (visited[x]) continue;
    if (mincost <= sum + W[x][y]) continue;
    visited[x] = 1;
    DFS(cnt + 1, start, y, sum + W[x][y]);
    visited[x] = 0;
  }
}
int Solve() {
  for (int i = 1; i <= N; i++) DFS(0, i, i, 0); // cnt, start, x, sum
  return mincost;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
