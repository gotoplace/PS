/*
https://www.acmicpc.net/problem/1182 : 부분수열의 합

DFS 풀이 v2
sel[] 배열을 사용하지 않고, DFS에 더한 경우, 더하지 않은 경우 재귀 호출
2016KB 0ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, S, sol;
int num[20 + 2];
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> num[i];
}
void DFS(int s, int sum) {
  if (s == N) return;
  if (sum + num[s] == S) sol++;
  DFS(s + 1, sum + num[s]); // num[s]를 더한 경우
  DFS(s + 1, sum); // 더하지 않은 경우
}
int Solve() {
  DFS(0, 0); // 최초 sum이 0부터 시작
  return sol;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
