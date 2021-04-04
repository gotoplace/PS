/*
https://www.acmicpc.net/problem/2309

DFS, 순차적으로 합을 구하여 7명 & 합 100을 만족하면 재귀 중단, sel[] == 1 해당되는 난쟁이만 출력
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int d[10], sel[10]; // sel[] : 조합을 얻고, 해당 값이 1인 경우만 d[] 출력하면 정답
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) cin >> d[i];
}
int DFS(int cnt, int s, int sum) {
  if (cnt == 7)
    if (sum == 100) return 1;
  for (int i = s; i < 9; i++) {
    if (sel[i] == 1) continue;
    sel[i] = 1;
    if (DFS(cnt + 1, i, sum + d[i])) return 1;
    sel[i] = 0;
  }
  return 0;
}
void Solve() {
  sort(d, d + 9);
  DFS(0, 0, 0); // cnt 0, s 0, sum 0부터 시작하는 점을 주의할 것
  for (int i = 0; i < 9; i++) {
    if (sel[i] == 0) continue;
    cout << d[i] << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
