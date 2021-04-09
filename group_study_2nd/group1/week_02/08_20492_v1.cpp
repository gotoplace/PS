/*
https://www.acmicpc.net/problem/20492 : 세금
수학, 사칙연산 문제
계산 단계에서는 소수점이 필요하므로 double을 사용하고, 결과 출력시 long long으로 cast함
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
void Solve() {
  double ans1, ans2;
  ans1 = N - N * 0.22;
  ans2 = N - (N - N * 0.8) * 0.22;
  cout << (long long)ans1 << " " << (long long)ans2 << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
