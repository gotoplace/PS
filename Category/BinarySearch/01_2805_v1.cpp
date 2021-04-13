/*
https://www.acmicpc.net/problem/2805 : 나무 자르기
이진 탐색 활용, 파라메트릭 서치
NOTE : 정렬, 이진 탐색으로 높이 최댓값 (mid)를 찾는다.
5924KB 164ms
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)1e6) // 1,000,000
using ll = long long;

int N, M;
int H[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> H[i];
}
int Calc(int h) {
  ll sum = 0; // 나무의 높이의 합은 항상 M보다 크거나 같기 때문에... int로 하면 overflow 발생
  for (int i = 0; i < N; i++) {
    if (H[i] <= h) continue;
    sum += (ll)H[i] - h; // long long cast 필요
    if (sum >= M) break; // M만큼 가능하다면 추가 탐색 불필요
  }
  if (sum >= M) return 1;
  return 0;
}
int Solve() {
  int len = 0; // h 최댓값
  // 정렬
  sort(H, H + N);
  int lo = 1, hi = H[N - 1]; // lo 설정 값 1로 해야 함.
  while (lo <= hi) { // 범위 조건 주의
    int mid = (lo + hi) / 2;
    if (Calc(mid)) { // 현재 높이로 가능하다면, 더 높여서 체크
      len = max(len, mid); lo = mid + 1;
    }
    else {
      hi = mid - 1; // 현재 높이로 M만큼 불가능하다면, 더 낮춰서 체크
    }
  }
  return len;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
