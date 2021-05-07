/*
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=645&sca=3050 : 회의실 배정
2248KB 1ms

회의를 최대한 많이 배정해야하는 문제
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
#define MAXN (500)
int N;
typedef struct _sched {
  int n, s, e;
} SCHED;
SCHED c_tables[MAXN + 10];
int sol[MAXN + 10];
 
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> c_tables[i].n >> c_tables[i].s >> c_tables[i].e;
}
bool comp(const SCHED &a, const SCHED &b) {
  if (a.e == b.e) return a.s < b.s;
  return a.e < b.e;
}
void Solve() {
  // 종료 시간 기준으로 정렬
  sort(c_tables, c_tables + N, comp);
  int cnt = 1, prev_e = c_tables[0].e;
  sol[0] = c_tables[0].n;
  for (int i = 1; i < N; i++) {
    if (prev_e <= c_tables[i].s) {
      prev_e = c_tables[i].e; sol[cnt++] = c_tables[i].n;
    }
  }
  // 출력
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) cout << sol[i] << " ";
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
