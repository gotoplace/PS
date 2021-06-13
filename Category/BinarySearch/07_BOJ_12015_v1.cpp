/*
https://www.acmicpc.net/problem/12015 : 가장 긴 증가하는 부분 수열 2
9832KB 164ms

일반적인 LIS 알고리즘으로 해결하는 문제이며, LIS를 구하고 길이를 출력

LIS를 vector로 구현시 12200KB 168ms
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
