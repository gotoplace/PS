/*
https://www.acmicpc.net/problem/2110 : 공유기 설치

이진탐색으로 풀이
참고 : https://jaimemin.tistory.com/966, https://blog.naver.com/pjok1122/221652210187

2796KB 20ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e5) // 200,000
#define endl '\n'

int X[MAXN + 10];
int N, C;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> X[i];
}
int Calc(int d) {
  int cnt = 1, cur = X[0]; // cnt는 무조건 1개로 시작
  for (int i = 1; i < N; i++) {
    if (d <= X[i] - cur) {  // mid 간격보다 X[i] - cur 간격이 크거나 같으면 설치 가능
      cnt++; cur = X[i];
    }
    if (cnt >= C) break; // C보다 크거나 같으면 추가 탐색 불필요
  }
  return (cnt >= C);
}
int Solve() {
  // 1. 정렬
  sort(X, X + N);
  // 2. 최대 간격 찾기
  int sol = 0, lo = 1, hi = X[N - 1] - X[0]; // 최소 거리, 최대 거리
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (Calc(mid)) { // mid 거리 만큼 설치 가능, 간격을 더 크게하여 확인
      sol = max(sol, mid);
      lo = mid + 1;
    }
    else hi = mid - 1; // C만큼 설치 불가하여, 간격을 더 작게, 촘촘하게 하여 확인
  }
  return sol;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
