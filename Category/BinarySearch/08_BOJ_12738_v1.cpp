/*
https://www.acmicpc.net/problem/12738 : 가장 긴 증가하는 부분 수열 3
9832KB 196ms

BOJ #12015와 거의 동일한 문제
-1,000,000,000 ≤ Ai ≤ 1,000,000,000
LIS 배열을 미리 초기화하는 것만 제외하면 동일한 코드로 해결 가능
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)1e6) // 1,000,000

int N, num[MAXN + 10], LIS[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> num[i];
}
int lowerBound(int lo, int hi, int target) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (target <= LIS[mid]) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
void Solve() {
  int len = 0;
  // 초기화
  for (int i = 0; i < N; i++) LIS[i] = -1000000001;
  for (int i = 0; i < N; i++) {
    if (LIS[len] < num[i]) LIS[++len] = num[i]; // 오름차순 입력이 가능하면 len 다음 요소에 입력
    else { // 그렇지 않으면, lowerBound가 찾아준 pos에 입력
      int pos = lowerBound(0, len, num[i]);
      LIS[pos] = num[i];
    }
  }
  cout << len << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
