/*
https://www.acmicpc.net/problem/1818 : 책정리

3584KB 24ms

가장 긴 증가하는 부분 수열: O(n log n)
참고 : LIS(Longest Increasing Subsequence) :: http://www.crocus.co.kr/583
참고 : https://www.crocus.co.kr/656, https://velog.io/@jua0610/%EB%B0%B1%EC%A4%80-1818-%EC%B1%85%EC%A0%95%EB%A6%AC-Lower-Bound
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)2e5) // 200,000

int N;
int books[MAXN + 10], LIS[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> books[i];
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
  int cnt = 0;
  LIS[0] = books[0]; // LIS 배열에 0번째 요소로 초기값 설정
  for (int i = 1, j = 0; i < N; i++) {
    if (LIS[j] < books[i]) LIS[++j] = books[i]; // i번째 번호가 LIS에 그냥 들어갈 수 있으면 현재 j 다음 위치 즉, ++j번째에 넣는다
    else { // 위치 교체를 해야 한다면, lowerBound()가 찾아준 pos 요소에 넣고, cnt 증가
      int pos = lowerBound(0, j, books[i]);
      LIS[pos] = books[i]; cnt++;
    }
  }
  cout << cnt << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
