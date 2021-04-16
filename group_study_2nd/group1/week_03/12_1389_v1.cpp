/*
https://www.acmicpc.net/problem/1389 : 케빈 베이컨의 6단계
노드 (멤버)간 모든 관계 최소 비용을 찾는 문제
플로이드 워셜 풀이
2064KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
#define INF ((int)1e9) // int overflow발생하지 않을 정도의 큰 수 사용
int dbg = 0;
int N, M;
int d[MAXN + 10][MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) { // INF로 초기화
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      d[i][j] = INF;
    }
  }
  for (int i = 0; i < M; i++) { // A, B 관계 초기화
    int A, B;
    cin >> A >> B;
    d[A][B] = d[B][A] = 1; // A와 B가 친구이면, B와 A도 친구이며, A와 B가 같은 경우는 없다
  }
}
int Solve() {
  int sol = 0;
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) { // i번 k번 관계와 k번 j번 관계를 더한 값이 더 좋으면
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  if (dbg) {
    for (int i = 1; i <= N; i++) {
      cout << "  ";
      for (int j = 1; j <= N; j++) {
        cout << d[i][j] << " ";
      }
      cout << endl;
    }
  }
  // 케빈 베이컨의 수가 가장 작은 사람을 출력. 최소값이 아닌 사람 번호 출력
  int minsum = INF;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += d[i][j];
    }
    if (minsum > sum) {
      minsum = sum; sol = i; // 최소값을 갖는 사람 번호 업데이트
    }
  }
  return sol;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
