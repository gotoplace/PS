/*
https://www.acmicpc.net/problem/2841 : 외계인의 기타 연주
19596KB 88ms
stack 풀이
다중 stack 또는 정렬 후 line 별 stack으로 처리해도 풀이 가능
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN ((int)5e5) // 500,000
int N, P;
using pii = pair<int, int>;
pii num[MAXN + 10];
#define line first
#define flat second
int stk[7][MAXN + 10];
int sp[7];
int cnt;
void push(int l, int p) {
  stk[l][sp[l]] = p; sp[l]++; cnt++;
}
void pop(int l) {
  sp[l]--; cnt++;
}
int top(int l) {
  return stk[l][sp[l] - 1];
}
int empty(int l) {
  return sp[l] == 0;
}
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> P;
  for (int i = 1; i <= N; i++) cin >> num[i].line >> num[i].flat;
}
int Solve() {
  for (int i = 1; i <= N; i++) {
    while (!empty(num[i].line) && top(num[i].line) > num[i].flat) 
      pop(num[i].line);
    if (!empty(num[i].line) && top(num[i].line) == num[i].flat) continue;
    push(num[i].line, num[i].flat);
  }
  return cnt;
}
int main() {
  InputData();
  int ans = Solve();
  cout << ans << endl;
  return 0;
}
