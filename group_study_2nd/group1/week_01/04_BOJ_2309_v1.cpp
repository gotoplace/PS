/*
https://www.acmicpc.net/problem/2309 : 일곱 난쟁이

DFS, 비트마스크 모두 가능
비트마스크 풀이
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int d[10], sol[8];
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) cin >> d[i];
}
void Solve() {
  sort(d, d + 9);
  int max = (1 << 9); // shift는 한 번만 하도록 변수로 값을 구해 놓음
  for (int i = 1; i < max; i++) {
    int cnt = 0, sum = 0;
    for (int k = 0; k < 9; k++) {
      if (i & (1 << k)) {
        sol[cnt++] = d[k]; sum += d[k];
      }
    }
    if (cnt == 7 && sum == 100) {
      for (int j = 0; j < 7; j++) cout << sol[j] << endl;
      return;
    }
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
