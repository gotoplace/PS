/*
https://www.acmicpc.net/problem/2309

DFS 풀이, 정렬 후, 순차적으로 합이 100이되면 DFS 중단, 결과 출력
2016KB 0ms
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int d[10], sel[10], d_sol[10]; // sel[] : 조합을 뽑기 위한 배열, d_sol[] : 정답 출력을 위한 배열
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
    sel[i] = 1; d_sol[cnt] = d[i];
    if (DFS(cnt + 1, i, sum + d[i])) return 1;
    sel[i] = 0; d_sol[cnt] = 0;
  }
  return 0;
}
void Solve() {
  sort(d, d + 9);
  DFS(0, 0, 0);
  for (int i = 0; i < 7; i++) cout << d_sol[i] << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
