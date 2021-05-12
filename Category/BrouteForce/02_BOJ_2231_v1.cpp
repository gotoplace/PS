/*
https://www.acmicpc.net/problem/2231 : 분해합
2016KB 4ms

입력된 N의 생성자를 찾는 문제.
순차탐색으로 N을 만족하는 생성자를 찾는데, 없으면 0 출력
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
int dsum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
void Solve() {
  int i, cnum = 0;
  for (i = 1; i < N; i++) {
    if (N == (i + dsum(i))) {
      cnum = i; break;
    }
  }
  cout << cnum << endl;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  Solve();
  return 0;
}
