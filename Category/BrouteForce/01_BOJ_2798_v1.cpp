/*
https://www.acmicpc.net/problem/2798 : 블랙잭
2016KB 0ms

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하는 문제.
기본적인 브루트 포스 타입.
DFS로 해결
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
int N, M, maxsum, num[MAXN +10];
int used[MAXN + 10];
int dbg = 0;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> num[i];
}
void DFS(int cnt, int s, int sum) {
  if (dbg) {
    cout << "  cnt: " << cnt << ", s: " << s << ", sum: " << sum << endl;
  }
  if (cnt == 3) {
    if (M >= sum) maxsum = max(maxsum, sum);
    return;
  }
  for (int i = s; i < N; i++) {
    if (used[i]) continue;
    used[i] = 1;
    DFS(cnt + 1, i, sum + num[i]);
    used[i] = 0;
  }
}
int Solve() {
  // 정렬
  sort(num, num + N);
  DFS(0, 0, 0);
  return maxsum;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
