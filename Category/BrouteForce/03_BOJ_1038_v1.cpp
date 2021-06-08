/*
https://www.acmicpc.net/problem/1038 : 감소하는 수
9836KB 0ms

참고 : https://yabmoons.tistory.com/553
DP로 분류되지 않는 것으로 판단되어 DP => sol 배열로 이름 변경

1. queue에 있는 값을 하나 꺼냄
2. 마지막 자리수 보다 작은 수를 마지막 자리로 갖는 수를 완성하여 다시 enqueue
3. 반복
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)1e6) // 1,000,000
using ll = long long;
int N;
ll sol[MAXN + 10]; // 자료형 주의

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
void Solve() {
  if (N <= 10) { // 10보다 작은 N은 그 자체가 답
    cout << N << endl; return;
  }
  queue<ll> q;
  for (int i = 1; i <= 9; i++) { // sol 배열에 미리 값을 채움
    q.push(i); sol[i] = i; // 0, 1, 2, ... 9
  }
  int idx = 10; // 10번째 채워질 차례
  while (idx <= N && q.empty() == false) {
    ll cur = q.front(); q.pop();
    int last = cur % 10; // 마지막 자리수 보다 작은 수를 찾아서 수를 완성하면 되므로 마지막 한 자리만 필요
    for (int i = 0; i < last; i++) {
      sol[idx] = cur * 10 + i;
      q.push(sol[idx]); idx++;
    }
  }
  if (idx >= N && sol[N] != 0) cout << sol[N] << endl; // sol 배열에 N 이상 찾았고, 해당 값이 0이 아니면 답
  else cout << -1 << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
