/*
https://www.acmicpc.net/problem/2630 : 색종이 만들기

D&C, 재귀함수, 2nd trial
2084KB, 0ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN (128)
#define endl '\n'

int N;
int paper[MAXN + 2][MAXN + 2];
int cnt[2]; // 0 : 흰색 종이 cnt, 1 : 파란색 종이 cnt

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }
}
void CountPaper(int x, int y, int size) {
  int cur = paper[x][y], diff = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (cur != paper[x + i][y + j]) { // 전달받은 좌표에서 i, j 위치
        diff = 1; break;
      }
    }
    if (diff == 1) break;
  }
  if (diff == 0) { // 모두 같은 색종이, 카운트 증가하고 리턴
    cnt[cur]++; return;
  }
  // diff == 1이므로, N/2로 분할 하여 체크 해야 함.
  size /= 2;
  CountPaper(x, y, size);
  CountPaper(x, y + size, size);
  CountPaper(x + size, y, size);
  CountPaper(x + size, y + size, size);
}
void Solve() {
  // 함수 호출 시작
  CountPaper(0, 0, N);
  // 흰색, 파란색 종이 개수 출력
  cout << cnt[0] << endl;
  cout << cnt[1] << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
