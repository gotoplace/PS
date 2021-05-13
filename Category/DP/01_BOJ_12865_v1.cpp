/*
https://www.acmicpc.net/problem/12865 : 평범한 배낭
44992KB 36ms

DP 문제 중 유명한 배낭 문제
참고 : https://hydroponicglass.tistory.com/50, https://huiyu.tistory.com/entry/DP-01-Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C

2차원 배열의 dp table로 접근하여 풀이하는 방법의 좋은 예제
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
#define MAXK ((int)1e5)
int N, K, W[MAXN + 10], V[MAXN + 10], dp[MAXN + 10][MAXK + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];
}
int Solve() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      // 현재 가방의 최대 무게 j 보다 현재 아이템의 무게가 더 크다면 넣을 수 없으므로
      // 이 전에 구한 아이템의 가치를 사용함
      if (W[i] > j) dp[i][j] = dp[i - 1][j];
      // 현재 가방의 최대 무게 j 보다 현재 아이템의 무게가 더 작으므로
      // 남은 공간에 해당되는 이 전에 구한 아이템의 가치와 현재 아이템의 가치를 더한 것
      // 이 전에 구한 아이템의 가치 중 큰 값을 사용함
      else dp[i][j] = max(dp[i - 1][j - W[i]] + V[i], dp[i - 1][j]);
    }
  }
  return dp[N][K];
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
