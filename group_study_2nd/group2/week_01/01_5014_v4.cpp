/*
https://www.acmicpc.net/problem/5014 : 스타트링크

DFS & 메모이제이션 풀이

참고 : https://2pound2pound.tistory.com/166
1. S < G, S > G 인 상황, 시작층이 목적지 층보다 낮은 경우, 높은 경우 모두 고려해야 한다.
2. 한 층을 갈 수 있는 방법은 아래층부터 오는 방법, 위층부터 오는 방법 모두 가능
현재 층에서 위, 아래로 갈 수 있는 층의 값을 갱신해주는 방식으로 진행, 즉, dp[cur + U] > dp[cur] + 1, dp[cur - D] > dp[cur] + 1와 같이
더 좋은 조건에서만 갱신한다.
만약 갈 수 없다면, 값이 바뀌지 않을 것이다.

21428KB, 20ms
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXF ((int)1e6) // 1,000,000
#define endl '\n'

int F, S, G, U, D;
int dp[MAXF + 10];

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> F >> S >> G >> U >> D;
}
void DFS(int cur) {
  if (cur + U <= F && dp[cur + U] > dp[cur] + 1) {
    dp[cur + U] = dp[cur] + 1; DFS(cur + U);
  }
  if (cur - D > 0 && dp[cur - D] > dp[cur] + 1) {
    dp[cur - D] = dp[cur] + 1; DFS(cur - D);
  }
}
int main() {
  InputData();
  for (int i = 0; i <= F; i++) dp[i] = INT_MAX;
  dp[S] = 0;
  DFS(S);
  if (dp[G] == INT_MAX) cout << "use the stairs" << endl;
  else cout << dp[G] << endl;
  return 0;
}
