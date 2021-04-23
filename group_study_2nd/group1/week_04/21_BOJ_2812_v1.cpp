/*
https://www.acmicpc.net/problem/2812 : 크게 만들기
stack 활용
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN ((int)5e5) // 500,000
int N, K;
char str[MAXN + 10];
int sp;
char stk[MAXN + 10];
void push(char c) { stk[sp++] = c; }
void pop() { sp--; }
char top() { return stk[sp - 1]; }
int empty() { return sp == 0; }

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K >> str;
}
void Solve() {
  for (int i = 0; str[i]; i++) {
    while (K > 0 && !empty() && top() < str[i]) { // K가 체크되어야 하고, stack에 작은 숫자가 있으면 모두 pop
      pop(); K--;
    }
    push(str[i]); // 그리고 push
  }
  while (K > 0 && !empty()) { pop(); K--; } // for loop 종료 후에도 K가 0보다 크면 모두 pop
  for (int i = 0; i < sp; i++) cout << stk[i]; // stack 배열 0부터 출력
  cout << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
