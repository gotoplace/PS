/*
https://www.acmicpc.net/problem/20126 : 교수님의 기말고사
2796KB 36ms
구현 문제.
참고 : https://prgmti1.tistory.com/entry/20126%EB%B2%88-%EA%B5%90%EC%88%98%EB%8B%98%EC%9D%98-%EA%B8%B0%EB%A7%90%EA%B3%A0%EC%82%AC
1. 0번째 시험이 시작하기 전에 시험을 진행하는 경우
2. 0~n-1번째 시험 사이에 껴서 시험을 보는 경우
3. 마지막 시험이 끝난 이후 시험을 보는 경우
4. 위 조건 모두 만족 안하는 경우
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN ((int)1e5) // 100,000
using pii = pair<int, int>;
#define x first
#define y second
pii sched[MAXN + 10];
int N, M, S;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M >> S;
  for (int i = 1; i <= N; i++) cin >> sched[i].x >> sched[i].y;
}
bool comp(const pii &a, const pii &b) {
  return a.x < b.x;
}
int Solve() {
  // 정렬
  sort(sched + 1, sched + N + 1, comp);
  // 1번째 시험이 시작하기 전에 시험을 진행하는 경우, 즉, 가장 처음에 시작해도 되는 경우
  // if (sched[1].x >= M) return 0; // 이 조건은 아래 for loop에서 처리되어 필요 없음.
  // sched[0].x + sched[0].y = 0, sched[1].x >= M 이면 가장 처음에 시작해도 되는 조건임.
  // 1 ~ N-1번째 시험 사이에 껴서 시험을 보는 경우
  for (int i = 0; i <= N - 1; i++) {
    if (sched[i + 1].x - (sched[i].x + sched[i].y) >= M) return sched[i].x + sched[i].y;
  }
  // 마지막 시험이 끝난 이후 시험을 보는 경우
  if (sched[N].x + sched[N].y + M <= S) return sched[N].x + sched[N].y;
  // 위 조건 모두 만족하지 않는 경우
  return -1;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
