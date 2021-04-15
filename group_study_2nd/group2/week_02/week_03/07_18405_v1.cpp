/*
https://www.acmicpc.net/problem/18405 : 경쟁적 전염
BFS, 원형큐로 풀이하면 실패됨.
선형큐로 풀이해야 함.

2992KB 4ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (200) // 200
#define MAXQ (MAXN * MAXN)
#define MOD (MAXQ - 1)

int dbg = 0;
int N, K, S, X, Y;
int vmap[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN +10];
typedef struct _pos {
  int x, y, t, num;
} POS;
POS que[MAXQ];
int wp, rp;
void push(int x, int y, int t, int num) {
  que[wp].x = x; que[wp].y = y; que[wp].t = t; que[wp].num = num;
  //wp = (wp + 1) & MOD;
  wp++;
}
//void pop() { rp = (rp + 1) & MOD; }
void pop() { rp++; }
POS front() { return que[rp]; }
int empty() { return wp == rp; }
// 문제 확산 조건 : 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int num;
      cin >> num;
      if (num > K || num == 0) continue;
      vmap[i][j] = num;
      push(i, j, 0, num); visited[i][j] = 1;
    }
  }
  cin >> S >> X >> Y;
}
bool comp(const POS &a, const POS &b) {
  return a.num < b.num;
}
int Solve() {
  // 큐 정렬
  sort(que, que + wp, comp);
  if (dbg) {
    for (int i = 0; i < wp; i++) {
      cout << "  x: " << que[i].x << ", y: " << que[i].y << ", t: " << que[i].t << ", num: " << que[i].num << endl;
    }
  }
  // 반복문
  while (!empty() && S--) { // 초단위 반복
    int size = wp - rp;
    while (size--) { // 1초당 큐 사이즈 만큼만 반복
      POS cur = front(); pop();
      //if (cur.t >= S) break; // cur.t >= S이면 break;
      for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i], ny = cur.y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (vmap[nx][ny] > 0 || visited[nx][ny]) continue;
        push(nx, ny, cur.t + 1, cur.num); vmap[nx][ny] = cur.num; visited[nx][ny] = 1;
      }
    }
  }
  if (dbg) {
    for (int i = 1; i <= N ; i++) {
      cout << "  ";
      for (int j = 1; j <= N; j++) {
        cout << vmap[i][j] << " ";
      }
      cout << endl;
    }
  }
  return vmap[X][Y];
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
