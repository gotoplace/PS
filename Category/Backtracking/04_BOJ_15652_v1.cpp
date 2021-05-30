/*
https://www.acmicpc.net/problem/15652 : N과 M (4)
2020KB 4ms

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
=> 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

15651과 같은 중복순열인데, 단 비내림차순이라는 조건을 만족하는 수열만 출력한다.
DFS 재귀를 호출하기 전 조건을 추가하면 됨.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (8)

int N, M;
int sol[MAXN + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
}
void PrintNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int cnt) {
  if (cnt == M) {
    PrintNum(); return;
  }
  for (int i = 1; i <= N; i++) {
    if (cnt > 0 && sol[cnt - 1] > i) continue;
    // cnt == 0이거나, cnt > 0 && sol[cnt - 1] <= i이면 재귀
    sol[cnt] = i;
    DFS(cnt + 1);
  }
}
int main() {
  InputData();
  DFS(0);
  return 0;
}
