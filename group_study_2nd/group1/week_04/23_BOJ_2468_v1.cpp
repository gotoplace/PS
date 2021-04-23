/*
https://www.acmicpc.net/problem/2468 : 안전 영역
특정 높이가 지정되지 않았으므로, 높이 1 ~ 최대 높이까지 체크해서 maxcnt를 구해야 함.
2940KB 20ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
int N, MAXH;
int omap[MAXN + 10][MAXN + 10];
int tmap[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];
using pii = pair<int, int>;
#define r first
#define c second
int wp, rp; // 매번 초기화 필요
pii que[MAXN * MAXN * 10];
void push(int r, int c) {
  que[wp].r = r; que[wp].c = c; wp++;
}
void pop() { rp++; }
pii front() { return que[rp]; }
int empty() { return wp == rp; }
// 상, 하, 좌, 우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  MAXH = 1;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> omap[i][j];
      if (MAXH < omap[i][j]) MAXH = omap[i][j]; // 입력 받을 때 최대 높이를 구해 놓자.
    }
}
void SetInfo(int h) {
  memset(visited, 0, sizeof(visited));
  memset(tmap, 0, sizeof(tmap));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (omap[i][j] <= h) continue;
      tmap[i][j] = omap[i][j];
    }
  }
}
void BFS(int r, int c) {
  wp = rp = 0; // que 초기화
  visited[r][c] = 1;
  push(r, c);
  while (!empty()) {
    pii cur = front(); pop();
    for (int i = 0; i < 4; i++) {
      int nr = cur.r + dr[i], nc = cur.c + dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
      if (visited[nr][nc] || tmap[nr][nc] == 0) continue;
      visited[nr][nc] = 1; push(nr, nc);
    }
  }
}
int Solve() {
  int maxcnt = 1; // 아무 지역도 물에 잠기지 않을 수도 있다. 그래프 요소는 1
  for (int h = 1; h <= MAXH; h++) { // 전체 loop
    // 초기화
    SetInfo(h);
    // 그래프 요소 최대 개수 구하기
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] || tmap[i][j] == 0) continue;
        BFS(i, j); cnt++;
      }
    }
    maxcnt = max(maxcnt, cnt);
  }
  return maxcnt;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
