/*
https://www.acmicpc.net/problem/9205 : 맥주 마시면서 걸어가기
2800KB 0ms
BFS로 풀이. DFS로도 가능할 것으로 보임.

node 배열, visited 배열 활용이 중요한 문제였음.
[0] : 집 좌표, [1] ~ [N] : 편의점 좌표, [N+1] : 최종 목적지 공연장 좌표
방문 가능한 조건은 abs(dest_x - cur.x) + abs(dest_y - cur.y) <= 1000
cur는 que front()임
dest는 node[i]
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
int T, N, SX, SY; // TC개수, 편의점 개수
using pii = pair<int, int>;
#define x first
#define y second
// [0] : 집, [1] ~ [N] : 편의점, [N + 1] : 공연장
pii node[MAXN + 10];
int visited[MAXN + 10];
pii que[MAXN * MAXN * 10];
int wp, rp;
void push(int x, int y) { que[wp].x = x; que[wp].y = y; wp++; }
void pop() { rp++; }
pii front() { return que[rp]; }
int empty() { return wp == rp; }
int dbg = 0;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> T;
}
int BFS() {
  wp = rp = 0;
  for (int i = 0; i <= N + 1; i++) visited[i] = 0;
  visited[0] = 1;
  push(SX, SY);
  while (!empty()) {
    pii cur = front(); pop();
    if (dbg) cout << "  cur: " << cur.x << ", " << cur.y << endl;
    for (int i = 1; i <= N + 1; i++) {
      if (visited[i]) continue;
      int dest_x = node[i].x, dest_y = node[i].y;
      if (abs(dest_x - cur.x) + abs(dest_y - cur.y) <= 1000) {
        visited[i] = 1; push(dest_x, dest_y);
      }
    }
    if (visited[N + 1]) break; // 방문했기 때문에 더 진행할 필요 없음
  }
  return visited[N + 1];
}
void Solve() {
  while (T--) {
    cin >> N >> SX >> SY;
    for (int i = 0; i <= N + 1; i++) {
      node[0].x = 0; node[0].y = 0; // 초기화
    }
    node[0].x = SX; node[0].y = SY; // 집 좌표 입력
    for (int i = 1; i <= N; i++) cin >> node[i].x >> node[i].y; // 편의점 좌표 입력
    cin >> node[N + 1].x >> node[N + 1].y; // 최종 목적지 공연장 입력
    if (BFS()) cout << "happy" << endl;
    else cout << "sad" << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
