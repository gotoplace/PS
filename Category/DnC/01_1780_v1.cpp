/*
https://www.acmicpc.net/problem/1780 : 종이의 개수
분할 정복, 재귀로 풀이, 2630 유사 문제, 거의 동일한 방법으로 해결
20872KB 356ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (2187) // 3 ^ 7

int N;
int paper[MAXN + 10][MAXN + 10];
int cnt[3];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j]; paper[i][j]++; // cnt index -1은 없으므로 구현 편의를 위해 +1 해줌
    }
  }
}
void CountPaper(int x, int y, int sz) {
  int cur = paper[x][y], diff = 0;
  if (sz == 1) { // 조건 추가, 결과는 동일함
    cnt[cur]++; return;
  }
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      if (cur != paper[x + i][y + j]) {
        diff = 1; break;
      }
    }
    if (diff == 1) break;
  }
  if (diff == 0) {
    cnt[cur]++; return;
  }
  sz /= 3; // 3으로 나누면 9개 종이로 나눌 수 있음
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      CountPaper(x + (i * sz), y + (j * sz), sz);
}
void Solve() {
  CountPaper(0, 0, N);
  for (int i = 0; i < 3; i++) cout << cnt[i] << endl; // 3가지 종류 결과 
}
int main() {
  InputData();
  Solve();
  return 0;
}
