/*
https://www.acmicpc.net/problem/15738 : 뒤집기
배열에 어떤 숫자가 들어있는지는 상관 없음.
연산에 따라서 K값 변화에 대한 풀이가 필요한 문제
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, K, M;
int Solve() {
  for (int i = 0; i < M; i++) {
    int len;
    cin >> len;
    // [1, len] 구간에서 찾기
    if (len > 0) {
      if (1 <= K && K <= len) K = 1 + len - K;
    }
    // [N - len + 1, N] 구간에서 찾기
    else {
      if (N + len + 1 <= K && K <= N) K = N * 2 + len + 1 - K;
    }
  }
  return K;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K >> M;
  int temp;
  for (int i = 0; i < N; i++) cin >> temp; // 배열에 어떤 숫자가 들어있는지는 상관 없음.
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
