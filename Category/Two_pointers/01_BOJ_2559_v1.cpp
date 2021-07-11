/*
https://www.acmicpc.net/problem/2559 : 수열
2412KB 8ms

온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오.
=> 0 ~ K - 1까지 구간합의 max를 구하고, K ~ N - 1까지 lo, hi를 증가하면서 구간합의 max를 구하면 해결 가능.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)1e5) // 100,000

int N, K, T[MAXN + 10];
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> T[i];
}
void Solve() {
  int lo = 0, hi = 0, sum = 0, max_sum = -10000001;
  // 1. T[0] ~ T[K - 1]까지 합을 구하고, max 확인
  while (hi < K) {
    sum += T[hi++];
  }
  max_sum = max(max_sum, sum);

  // 2. N - 1까지, lo & hi 증가하면서 합을 구하고, max 확인 
  while (hi < N) {
    sum -= T[lo++];
    sum += T[hi++];
    max_sum = max(max_sum, sum);
  }
  cout << max_sum << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
