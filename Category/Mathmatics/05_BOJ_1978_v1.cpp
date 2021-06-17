/*
https://www.acmicpc.net/problem/1978 : 소수 찾기
2020KB 0ms

참고 : https://ko.wikipedia.org/wiki/%EC%86%8C%EC%88%98_(%EC%88%98%EB%A1%A0)
https://jongmin92.github.io/2017/11/05/Algorithm/Concept/prime/

단순 접근 방법으로 풀이
N이 소수라면, 2 ~ N - 1 범위의 수로 나누어 떨어지지 않는다.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (100)

int N, num[MAXN + 10];
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> num[i];
}
int IsPrimeNum(int n) {
  int isPrimeNum = 1;
  for (int i = 2; i < n; i++) {
    if (n % i) continue;
    isPrimeNum = 0; break; // 2 ~ N - 1 값 중 나누어 떨어진다면 소수가 아니므로 루프 탈출
  }
  return isPrimeNum;
}
void Solve() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (num[i] == 1) continue;
    if (IsPrimeNum(num[i])) cnt++;
  }
  cout << cnt << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
