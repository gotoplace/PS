/*
http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=391&sca=4070 : 등산로 찾기
10,148KB 8ms
정올 문제.
메모리 제한이 없다면, 선형큐를 사용하자!

최단거리 찾기
산의 바깥지역(높이 0)으로부터 정상에 도달하기 위하여 가장 경제적인 루트를 탐색
등산가가 산에 오르는 시작점의 위치는 산의 바깥지역의 어디에서 시작해도 좋다.

문제 접근 방법
시작할 때, 바깥부분에서 접근하는 조건으로 시작해야 함.
바깥부분 0에서 올라오면 visited[][] 값은 vmap[][] * vmap[][]값이 됨
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
#define MAXN (100)
#define INF ((int)1e9)
int vmap[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];
int N, X, Y;
// 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
typedef struct _pos {
  int x, y;
} POS;
POS que[MAXN * MAXN * MAXN];
int wp, rp;
void push(int x, int y) {
  que[wp].x = x; que[wp].y = y;
  wp++;
}
void pop() { rp++; }
POS front() { return que[rp]; }
int empty() { return wp == rp; }
int dbg = 0;
 
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> X >> Y;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> vmap[i][j];
    }
  }
}
int BFS() {
  while (!empty()) {
    POS cur = front(); pop();
    //if (cur.x == X && cur.y == Y) break; // 확산하도록 empty()까지 진행해야 함
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i], ny = cur.y + dy[i];
      if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
      int cost = 0;
      if (vmap[cur.x][cur.y] > vmap[nx][ny]) { // 내려가는 경우
        cost = vmap[cur.x][cur.y] - vmap[nx][ny];
      }
      else if (vmap[cur.x][cur.y] < vmap[nx][ny]) { // 올라가는 경우
        int diff = vmap[nx][ny] - vmap[cur.x][cur.y];
        cost = diff * diff;
      }
      else cost = 0;
      if (visited[nx][ny] > visited[cur.x][cur.y] + cost) {
        visited[nx][ny] = visited[cur.x][cur.y] + cost;
        push(nx, ny);
      }
    }
  }
  if (dbg) {
    for (int i = 1; i <= N; i++) {
      cout << "  ";
      for (int j = 1; j <= N; j++) {
        if (visited[i][j] == INF) cout << "F" << " ";
        else cout << visited[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return visited[X][Y];
}
int Solve() {
  // visited 배열 INF 초기화
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      visited[i][j] = INF;
    }
  }
  // 바깥부분 0에서 올라오면 visited[][] 값은 vmap[][] * vmap[][]값이 됨
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == 1 || i == N || j == 1 || j == N) {
        push(i, j); visited[i][j] = vmap[i][j] * vmap[i][j];
      }
    }
  }
  return BFS();
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
