/*
https://www.acmicpc.net/problem/10816 : 숫자 카드 2
3972KB 328ms

int 배열, lower & upper boud 함수 직접 구현
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)5e5)

int N, M;
int num[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> num[i];
  cin >> M;
}
int lowerBound(int target) {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (target <= num[mid]) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
int upperBound(int target) {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (target < num[mid]) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
void Solve() {
  sort(num, num + N);
  for (int i = 0; i < M; i++) {
    int card;
    cin >> card;
    cout << upperBound(card) - lowerBound(card) << " ";
  }
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
