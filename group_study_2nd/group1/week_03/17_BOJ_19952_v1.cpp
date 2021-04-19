/*
https://www.acmicpc.net/problem/19952 : 인성 문제 있어??
13828KB 4ms
문제 조건 이해가 어려웠음. BFS 해결 
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
int T, H, W, O, F, SX, SY, EX, EY; // TC, 세로, 가로, 좌표개수, 초기 힘, 출발X, 출발Y, 도착X, 도착Y
int vmap[MAXN + 10][MAXN + 10]; // T만큼 매번 초기화 필요
int visited[MAXN + 10][MAXN + 10]; // T만큼 매번 초기화 필요

int wp, rp;
typedef struct _pos {
  int x, y, f;
} POS;
POS que[MAXN * MAXN * MAXN];
void push(int x, int y, int f) { que[wp].x = x; que[wp].y = y; que[wp].f = f; wp++; }
void pop() { rp++; }
POS front() { return que[rp]; }
int empty() { return wp == rp; }
// 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dbg = 0;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> T;
}
int BFS() {
  int found = 0;
  wp = rp = 0;
  visited[SX][SY] = 1;
  push(SX, SY, F);
  while (!empty()) {
    POS cur = front(); pop();
    if (cur.x == EX && cur.y == EY) { // 목적지이면 found 설정, break
      found = 1; break;
    }
    if (cur.f == 0) continue; // 현재 남아있는 힘이 없으면 skip
    for (int i = 0; i < 4; i++) { // 확산 시도
      int nx = cur.x + dx[i], ny = cur.y + dy[i];
      if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
      if (visited[nx][ny]) continue;
      if (vmap[nx][ny] - vmap[cur.x][cur.y] <= cur.f) { // 현재 남아있는 힘이 크거나 같아야 함.
        visited[nx][ny] = 1; push(nx, ny, cur.f - 1); // 매 이동이 완료될 시에 인성이의 남은 힘은 1씩 감소
      }
    }
  }
  if (dbg) {
    for (int i = 1; i <= H; i++) {
      cout << "  ";
      for (int j = 1; j <= W; j++) {
        cout << visited[i][j] << " ";
      }
      cout << endl;
    }
  }
  return found;
}
void Solve() {
  while (T--) {
    cin >> H >> W >> O >> F >> SX >> SY >> EX >> EY;
    for (int i = 0; i <= MAXN; i++) { // TC 마다 초기화
      for (int j = 0; j <= MAXN; j++) {
        vmap[i][j] = visited[i][j] = 0;
      }
    }
    for (int i = 0; i < O; i++) { // 좌표 입력
      int X, Y, C;
      cin >> X >> Y >> C;
      vmap[X][Y] = C;
    }
    if (BFS()) cout << "잘했어!!" << endl;
    else cout << "인성 문제있어??" << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
