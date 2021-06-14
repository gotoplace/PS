/*
https://www.acmicpc.net/problem/1037 : 약수
2020KB 0ms

참고 : https://sihyungyou.github.io/baekjoon-1037/

어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
=> 약수가 모두 주어지면 가장 작은 약수와 가장 큰 약수를 곱하면 N을 구할 수 있음
=> 최대 50개 약수를 모두 입력 받고 저장한 후, 정렬해도 되지만, min, max만 알면 되는 문제
=> int범위로 해결 가능한 문제
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int M;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> M;
}
void Solve() {
  int min = ((int)1e7), max = 0;
  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    if (min > num) min = num;
    if (max < num) max = num;
  }
  cout << min * max << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
