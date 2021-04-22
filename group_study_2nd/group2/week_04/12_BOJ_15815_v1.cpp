/*
https://www.acmicpc.net/problem/15815 : 천재 수학자 성필
단순 stack 응용
2016KB 0ms
숫자 a, b 뽑아낼 때 순서에 주의
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (100)
char str[MAXN + 10];
using ll = long long;
stack<int> istk;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> str;
}
int Solve() {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= '0' && str[i] <= '9') istk.push(str[i] - '0');
    else {
      int a, b;
      switch (str[i]) {
      case '+':
        b = istk.top(); istk.pop();
        a = istk.top(); istk.pop();
        istk.push(a + b);
        break;
      case '-':
        b = istk.top(); istk.pop();
        a = istk.top(); istk.pop();
        istk.push(a - b);
        break;
      case '*':
        b = istk.top(); istk.pop();
        a = istk.top(); istk.pop();
        istk.push(a * b);
        break;
      case '/':
        b = istk.top(); istk.pop();
        a = istk.top(); istk.pop();
        istk.push(a / b);
        break;
      }
    }
  }
  return istk.top();
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
