/*
https://www.acmicpc.net/problem/17427 : 약수의 합2
2020KB 0ms

참고 : https://suhwanc.tistory.com/55, https://from2020.tistory.com/27

N = 10일 때)
[1] [1, 2] [1, 3] [1, 2, 4] [1, 5] [1, 2, 3, 6] [1, 7] [1, 2, 4, 8] [1, 3, 9] [1, 2, 5, 10]

잘 살펴보면,
[1이 10번, 2가 5번, 3이 3번, 4가 2번 5가 2번, 6이 1번, ... ,10이 1번] 이렇게 들어가는 규칙이 있음

1 * (10 / 1)번 = 10
2 * (10 / 2)번 = 10
3 * (10 / 3)번 = 9 ...
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int X;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> X;
}
void Solve() {
  long long sol = 0;
  for (int i = 1; i <= X; i++) {
    sol += i * (X / i);
  }
  cout << sol << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
