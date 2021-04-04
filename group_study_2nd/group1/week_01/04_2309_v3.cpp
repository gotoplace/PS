/*
https://www.acmicpc.net/problem/2309
DFS, total sum에서 난쟁이 키를 빼면서 합이 100이면 중단, 결과 출력
2016KB 0ms
*/

#include <bits/stdc++.h>
using namespace std;

int d[10], sel[10], d_sol[10], total;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) {
    cin >> d[i]; total += d[i];
  }
}
int DFS(int cnt, int s, int sum) {
  if (cnt == 2)
    if (sum == 100) return 1;
  for (int i = s; i < 9; i++) {
    if (sel[i] == 1) continue;
    sel[i] = 1; d_sol[i] = 1;
    if (DFS(cnt + 1, i, sum - d[i])) return 1;
    sel[i] = 0; d_sol[i] = 0;
  }
  return 0;
}
void Solve() {
  sort(d, d + 9);
  DFS(0, 0, total);
  for (int i = 0; i < 9; i++) {
    if (d_sol[i] == 1) continue; // 해당 난쟁이는 스킵
    cout << d[i] << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
