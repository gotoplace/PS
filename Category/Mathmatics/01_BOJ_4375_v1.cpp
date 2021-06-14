/*
https://www.acmicpc.net/problem/4375 : 1
2020KB 0ms

2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
1로 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
=> 자리수의 개수를 출력해야함
=> 1로만 이루어진 수를 계속 증가시키면서 구하면 long long 범위를 초과할 수 있음
=> n의 배수는 n으로 나누어 떨어진다는 나머지의 성질을 이용해야함
=> num % N = 0 되는 시점의 i 값이 자리수를 의미함
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N;
void Solve() {
  while (cin >> N) {
    int num = 0;
    for (int i = 1; i <= N; i++) {
      num = num * 10 + 1;
      num %= N;
      if (num == 0) {
        cout << i << endl;
        break;
      }
    }
  }
}
int main() {
  Solve();
  return 0;
}
