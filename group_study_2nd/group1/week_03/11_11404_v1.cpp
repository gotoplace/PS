/*
https://www.acmicpc.net/problem/11404 : 플로이드
플로이드 워셜 풀이
2064KB 24ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
#define INF ((int)1e9) // int overflow되지 않을 정도의 큰수 사용
int dbg = 0;
int N, M;
int d[MAXN + 10][MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (i == j) continue; // [i][j]는 0으로 유지되어야 함
      d[i][j] = INF; // 나머지는 INF로 우선 초기화
    }
  }
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    if (d[A][B] > C) d[A][B] = C; // 같은 경로에 비용이 다른 경우도 있음
  }
}
void Solve() {
  if (dbg) {
    for (int i = 1; i <= N; i++) {
      cout << "  ";
      for (int j = 1;  j <= N; j++) cout << d[i][j] << " ";
      cout << endl;
    }
  }
  // 플로이드 워셜
  for (int k = 1; k <= N; k++) { // 거쳐가는 노드
    for (int i = 1; i <= N; i++) { // 시작 노드
      for (int j = 1; j <= N; j++) { // 도착 노드
        // if (i == j || i == k || k == j) continue; // 있으나 없으나 별 차이 없음
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }
  // 출력
  for (int i = 1; i <= N; i++) { // 시작 노드
    for (int j = 1; j <= N; j++) { // 도착 노드
      if (d[i][j] == INF) cout << 0 << " ";
      else cout << d[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
