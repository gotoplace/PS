/*
https://www.acmicpc.net/problem/20492 : 세금
N은 1000의 배수이므로, N * 0.78, N * 0.956이 성립함
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
  cout << (int)(0.78 * N) << " " << (int)(0.956 * N) << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
