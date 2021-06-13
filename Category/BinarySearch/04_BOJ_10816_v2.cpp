/*
https://www.acmicpc.net/problem/10816 : 숫자 카드 2
5224KB 320ms

vector, 함수 구현
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, M;
vector<int> num;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  int n;
  for (int i = 0; i < N; i++) {
    cin >> n; num.push_back(n);
  }
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
  sort(num.begin(), num.end());
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
