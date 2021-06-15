/*
두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다.
예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다.

자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다.
x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.

자연수 N이 주어졌을 때, g(N)을 구해보자.

g(x) = f(1) + f(2) + f(3) ... + f(x-1) + f(x)

참고 : 

출처: https://codingdog.tistory.com/entry/약수-구하기-알고리즘-n05만-보고도-구할-수-있다

시간 초과
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int X;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> X;
}
int divSum(int y) {
  int sum = 0;
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      if (i == (y / i)) sum += i;
      else sum += (i + y / i);
    }
  }
  return sum;
}
void Solve() {
  // y : 1 ~ X까지, 각 정수에 대한 f(y)를 구하고, 그 값을 누적한다
  long long totalSum = 0;
  for (int i = 1; i <= X; i++) {
    totalSum += divSum(i);
  }
  cout << totalSum << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
