/*
https://www.acmicpc.net/problem/6549 : 히스토그램에서 가장 큰 직사각형

세그먼트 트리를 활용한 풀이 방법도 존재함.

stack 풀이
참고 : https://yangorithm.tistory.com/165
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5) // 100,000
#define endl '\n'
using ll = long long;
int N;
int H[MAXN + 10];
int sp;
int stk[MAXN + 10]; // TC마다 sp로 초기화를 하기 위해 STL 사용하지 않음.
void push(int idx) { stk[sp++] = idx; }
void pop() { sp--; }
int top() { return stk[sp - 1]; }
int empty() { return sp == 0; }
int dbg = 0;
void printStack() {
  if (dbg) {
    for (int i = 0; i < sp; i++) {
      cout << stk[i] << " ";
    }
    cout << endl;
  }
}
void Solve() {
  ll sol = 0;
  while (1) {
    cin >> N;
    if (N == 0) break;
    sol = 0; sp = 0;
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) {
      // H[top()] < H[i] : stack에 push
      // H[top()] > H[i] : 넓이를 구함, 마지막에 push
      while (!empty() && H[top()] > H[i]) {
        ll h = H[top()]; pop(); ll w = i;
        if (!empty()) w = i - top() - 1; // empty가 아니면, 가로 길이가 증가될 수 있음
        sol = max(sol, h * w);
      }
      push(i);
    }
    printStack();
    // N - 1까지 체크 완료 후, empty가 아니면
    // 가로 길이를 N으로 하고 위에 과정을 반복하면 위에서 구하지 못한 사각형들의 넓이를 구할 수 있으며, 최대 넓이 갱신
    while (!empty()) {
      ll h = H[top()]; pop(); ll w = N;
      if (!empty()) w = N - top() - 1;
      sol = max(sol, h * w);
    }
    cout << sol << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
