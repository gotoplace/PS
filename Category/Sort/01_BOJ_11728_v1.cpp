/*
https://www.acmicpc.net/problem/11728 : 배열 합치기
9832KB 664ms

정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.
=> 하나의 배열에 배열 A, B에 해당되는 값을 순차적으로 입력하고, 정렬하면 되는 문제
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)1e6) // 1,000,000

int N, M, A[MAXN * 2 + 10];
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  int a, idx = 0;
  for (int i = 0; i < N; i++) {
    cin >> a; A[idx++] = a;
  }
  for (int i = 0; i < M; i++) {
    cin >> a; A[idx++] = a;
  }
}
void Solve() {
  sort(A, A + (N + M));
  for (int i = 0; i < (N + M); i++) cout << A[i] << " ";
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
