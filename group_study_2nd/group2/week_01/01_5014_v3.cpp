/*
https://www.acmicpc.net/problem/5014 : 스타트링크

참고 : http://melonicedlatte.com/algorithm/2018/11/11/210348.html
2016KB, 0ms
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXF ((int)1e6) // 1,000,000
#define endl '\n'

int F, S, G, U, D;
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> F >> S >> G >> U >> D;
}
int Solve() {
  int cur = S;
  for (int i = 0; i < MAXF; i++) {
    if (cur == G) return i;
    if (cur + U > F && cur - D < 1) return -1;
    if (cur < G && cur + U <= F) cur += U;
    else if (!(cur > G && cur - D < 1)) cur -= D;
  }
  return -1;
}
int main() {
  InputData();
  int ans = Solve();
  if (ans == -1) cout << "use the stairs" << endl;
  else cout << ans << endl;
}
