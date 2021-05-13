/*
https://www.acmicpc.net/problem/1806 : 부분합

10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 문제.

반복 조건 : left <= right
sum >= S이면, sum에서 num[left]를 빼고, left++
right == N이면 break
sum < S이면, sum에 num[right]를 더하고, right++
2408KB 8ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5) // 100,000
#define endl '\n'
int N, S;
int num[MAXN + 10];
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> num[i];
}
void Solve() {
  int left = 0, right = 0, sum = 0, len = INT_MAX;
  while (left <= right) {
    if (sum >= S) { // S보다 크거나 같으면, sum에서 num[left]를 빼고, left++
      len = min(len, right - left);
      sum -= num[left++];
    }
    else if (right == N) break; // right++ > N 조건 방지, 먼저 체크해야 함
    else sum += num[right++]; // S보다 작으면, sum에 num[right]를 더하고, right++
  }
  if (len == INT_MAX) cout << 0 << endl;
  else cout << len << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
