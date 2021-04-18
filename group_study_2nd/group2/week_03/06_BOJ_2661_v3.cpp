/*
https://www.acmicpc.net/problem/2661 : 좋은수열
STL substr 사용 버전, 로직은 같음
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
string sol;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
int Check(int len) {
  if (len < 4) return 0; //2자리는 따로 걸름, 4자리 이상만 체크
  // 2부터 len까지 자리수 하나씩 늘려가면서
  for (int i = 2; i <= len / 2; i++) {
    for (int j = 0; j + 2 * i <= len; j++) {
      // 같은 수열, 나쁜 수열이므로 return 1
      if (sol.substr(j, i) == sol.substr(i + j, i)) return 1;
    }
  }
  return 0;
}
int DFS(int cnt, int s) {
  if (Check(cnt)) { // 중복된 숫자, 나쁜수열
    return 0;
  }
  if (cnt >= N) { // 좋은 수열 찾았음
    cout << sol << endl;
    return 1;
  }
  for (int i = 1; i <= 3; i++) {
    if (s == i) continue; // 같은 수, 좋은 수열 아님
    sol.push_back(i + '0');
    if (DFS(cnt + 1, i)) return 1; // 부분 수열 중 좋은 수열
    sol.pop_back();
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
