/*
https://www.acmicpc.net/problem/2661 : 좋은수열
strncmp 버전

2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN 82
int N;
char sol[MAXN];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
int Check(int len) {
  if (len < 4) return 0; //2자리는 따로 걸름, 4자리 이상만 체크
  // 2부터 len까지 자리수 하나씩 늘려가면서
  for (int i = 2; i <= len / 2; i++) {
    for (int j = 0; j + 2 * i <= len; j++) {
      if (strncmp(&sol[j], &sol[i + j], i) == 0) return 1;
    }
  }
  return 0;
}
int DFS(int cnt, int s) {
  if (Check(cnt)) { // 중복된 숫자, 나쁜수열
    return 0;
  }
  if (cnt >= N) { // 좋은 수열 찾았음
    for (int i = 0; i < N; i++) cout << sol[i];
    cout << endl;
    return 1;
  }
  for (int i = 1; i <= 3; i++) {
    if (s == i) continue; // 같은 수, 좋은 수열 아님
    sol[cnt] = i + '0';
    if (DFS(cnt + 1, i)) return 1; // 부분 수열 중 좋은 수열
    sol[cnt] = 0;
  }
  return 0;
}
void Solve() {
  DFS(0, 0);
}
int main() {
  InputData();
  Solve();
  return 0;
}
