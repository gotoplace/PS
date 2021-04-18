/*
https://www.acmicpc.net/problem/17182 : 우주 탐사선
1. 플로이드 워셜 구현으로 최단거리 갱신
2. 순열로 최단거리 구하기
N이 작아서 가능할 것
# STL next_permutation 활용 : DFS() 구현보다 성능이 더 좋음
2016KB 28ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define INF ((int)1e9)
int N, K;
int T[10 + 2][10 + 2];
int mincost = INF;
int sel[10 + 2]; // 순열 사용 여부
int order[10 + 2]; // 방문 순서
int dbg = 0;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> T[i][j];
    }
  }
}
void Calc() {
  if (order[0] != K) return; // 시작점이 K와 같지 않다면 무효
  int sum = 0;
  for (int i = 1; i < N; i++) {
    int cur = order[i - 1], next = order[i];
    sum += T[cur][next];
  }
  mincost = min(mincost, sum);
}
int Solve() {
  // 플로이드 워셜 : 모든 노드의 최단거리 갱신
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (T[i][j] > T[i][k] + T[k][j]) T[i][j] = T[i][k] + T[k][j];
      }
    }
  }
  // 순열로 최단 거리 구하기, STL next_permutation 활용
  for (int i = 0; i < N; i++) order[i] = i;
  do {
    Calc();
  } while (next_permutation(order, order + N));
  return mincost;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
