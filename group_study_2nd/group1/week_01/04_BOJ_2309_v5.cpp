/*
https://www.acmicpc.net/problem/2309 : 일곱 난쟁이

DFS, 입력 받은 난쟁이 total합을 구한 후, 순차적으로 빼면서 cnt 2 && sum 100을 만족하면 재귀 중단, sel[]에 해당되지 않는 난쟁이만 출력
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;

int d[10], sel[10], total;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) {
    cin >> d[i]; total += d[i];
  }
}
int DFS(int cnt, int s, int sum) {
  if (cnt == 2) {
    if (sum == 100) return 1;
    return 0;
  }
  for (int i = s; i < 9; i++) {
    if (sel[i] == 1) continue;
    sel[i] = 1;
    if (DFS(cnt + 1, i, sum - d[i])) return 1;
    sel[i] = 0;
  }
  return 0;
}
void Solve() {
  sort(d, d + 9);
  DFS(0, 0, total);
  for (int i = 0; i < 9; i++) {
    if (sel[i] == 1) continue; // 해당 난쟁이는 스킵
    cout << d[i] << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
