/*
https://www.acmicpc.net/problem/20494 : 스시
2016KB 0ms
단순 문자열 처리 문제
각 멤버가 원하는 스시 리스트 개수 만큼 셰프가 많들어야 함, 결국 문자열 길이의 합
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
int Solve() {
  int total = 0;
  while (N--) {
    string str;
    cin >> str; total += str.size();
  }
  return total;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
