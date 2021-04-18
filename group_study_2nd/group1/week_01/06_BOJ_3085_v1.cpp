/*
https://www.acmicpc.net/problem/3085 : 사탕 게임
브루트포스
N : 5인 경우, ((N * N - 1) * 2)^2 = 1600
N : 55인 경우, 35,283,600
2020KB 32ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N, maxcnt = 1;
char B[55 + 5][55 + 5];
int dbg = 0, callcnt = 0;
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> B[i];
}
void Calc() {
  int cnt = 1;
  for (int i = 0; i < N; i++) { // 가로 방향 연속으로 존재하는지 체크
    cnt = 1; // 1로 초기화하여 반복
    for (int j = 0; j < N - 1; j++) {
      if (dbg) callcnt++;
      if (B[i][j] == B[i][j + 1]) cnt++; // 연속하여 같으면 증가
      else cnt = 1; // 다른 값이면 1로 초기화
      maxcnt = max(maxcnt, cnt);
    }
  }
  for (int i = 0; i < N; i++) { // 세로 방향 연속으로 존재하는지 체크
    cnt = 1; // 1로 초기화하여 반복
    for (int j = 0; j < N - 1; j++) {
      if (dbg) callcnt++;
      if (B[j][i] == B[j + 1][i]) cnt++; // 연속하여 같으면 증가
      else cnt = 1; // 다른 값이면 1로 초기화
      maxcnt = max(maxcnt, cnt);
    }
  }
}
int Solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      swap(B[i][j], B[i][j + 1]); // 우측
      Calc();
      swap(B[i][j], B[i][j + 1]);

      swap(B[j][i], B[j + 1][i]); // 하단
      Calc();
      swap(B[j][i], B[j + 1][i]);
    }
  }
  if (dbg) cout << "  callcnt: " << callcnt << endl;
  return maxcnt;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
