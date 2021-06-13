/*
https://www.acmicpc.net/problem/10816 : 숫자 카드 2
3968KB 328ms
int 배열, STL 사용
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)5e5) // 500,000
#define endl '\n'

int N, M;
int A[MAXN + 10];
int T;

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}
void Solve() {
  // 정렬
  sort(A, A + N);
  // 반복문 : upper_bound() - lower_bound()
  cin >> M;
  while (M--) {
    cin >> T;
    cout << upper_bound(A, A + N, T) - lower_bound(A, A + N, T) << " ";
  }
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
