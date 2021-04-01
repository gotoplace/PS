/*
6436KB, 8ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXF ((int)1e6) // 1,000,000
#define MAXQ (1<<16) // 65536 for circular Queue
#define MOD (MAXQ - 1)
#define step first
#define cnt second
#define endl '\n'
using pii = pair<int, int>;

pii que[MAXQ];
int wp, rp;
void push(int step, int cnt) {
  que[wp].step = step; que[wp].cnt = cnt;
  wp = (wp + 1) & MOD;
}
void pop() { rp = (rp + 1) & MOD;}
pii front() { return que[rp]; }
int empty() { return wp == rp; }
int visited[MAXF + 10];

int F, S, G, U, D;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> F >> S >> G >> U >> D;
}
int BFS() {
  int sol = -1;
  visited[S] = 1;
  push(S, 0);
  while(!empty()) {
    pii cur = front(); pop();
    if (cur.step == G) {
      sol = cur.cnt; break;
    }
    if (cur.step + U <= F && visited[cur.step + U] == 0) {
      visited[cur.step + U] = 1; push(cur.step + U, cur.cnt + 1);
    }
    if (cur.step - D > 0 && visited[cur.step - D] == 0) {
      visited[cur.step - D] = 1; push(cur.step - D, cur.cnt + 1);
    }
  }
  return sol;
}
int main() {
  InputData();
  int ans = BFS();
  if (ans == -1) cout << "use the stairs" << endl;
  else cout << ans << endl;
}
