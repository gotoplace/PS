/*
https://www.acmicpc.net/problem/20921 : 그렇고 그런 사이
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, K, idx;
int ans[5000];
int used[5000];
void Solve() {
  for (int i = N; i >= 1; i--) {
    // 현재 숫자 i로 만들 수 있는 그런사이 개수 확인
    // 별도 배열에 저장, 관련 변수 처리
    if (K >= i - 1) {
      ans[idx++] = i;
      used[i] = 1;
      K -= i - 1;
    }
  }
  // 선택된 숫자 출력
  for (int i = 0; i < idx; i++) cout << ans[i] << " ";
  // 나머지 선택되지 않은 숫자들 오름차순으로 출력
  for (int i = 1; i <= N; i++) {
    if (used[i] == 0) cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  Solve();
  return 0;
}
