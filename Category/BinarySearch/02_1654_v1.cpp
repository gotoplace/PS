/*
https://www.acmicpc.net/problem/1654 : 랜선 자르기
이진 탐색, 파라메트릭 서치로 풀이
2805와 동일한 방법으로 접근, int overflow 주의
2056KB 4ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXK ((int)1e4) // 10,000
using ll = long long;
int K, N;
int L[MAXK + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> K >> N;
  for (int i = 0; i < K; i++) cin >> L[i];
}
int Calc(ll h) {
  ll cnt = 0;
  for (int i = 0; i < K; i++) {
    if (L[i] < h) continue;
    cnt += (ll)L[i] / h; // 나눈 몫을 cnt에 누적하여 N개를 만족하는지 체크
    if (cnt >= N) break;
  }
  if (cnt >= N) return 1;
  return 0;
}
ll Solve() {
  ll len = 0;
  sort(L, L + K);
  ll lo = 1, hi = L[K - 1];
  while (lo <= hi) {
    ll mid = (ll)(lo + hi) / 2;
    if (Calc(mid)) {
      len = max(len, mid); lo = mid + 1;
    }
    else hi = mid - 1;
  }
  return len;
}
int main() {
  InputData();
  ll ans = Solve();
  cout << ans << endl;
  return 0;
}
