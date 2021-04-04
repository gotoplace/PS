/*
https://www.acmicpc.net/problem/7568 : 덩치
N : 50이므로, 단순하게 O(N^2)으로 해결
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, men[50 + 10][2];
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> men[i][0] >> men[i][1];
}
void Solve() {
  for (int i = 0; i < N; i++) {
    int cnt = 1; // 자기 자신은 k + 1등 이므로
    for (int j = 0; j < N; j++)
      if (men[i][0] < men[j][0] && men[i][1] < men[j][1]) cnt++;
    cout << cnt << " ";
  }
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
