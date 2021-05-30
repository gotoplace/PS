/*
https://www.acmicpc.net/problem/15650 : N과 M (2)
2020KB 0ms

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
=> sol배열에 i를 순서대로 대입해야 오름차순으로 출력됨
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (8)
int N, M;
int used[MAXN + 2], sol[MAXN + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
}
void printNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int s, int cnt) {
  if (cnt == M) {
    printNum(); return;
  }
  for (int i = s; i <= N; i++) { // 재귀로 전달 받은 값으로 시작, 중복 제거 방법
    if (used[i]) continue;
    used[i] = 1; sol[cnt] = i;
    DFS(i + 1, cnt + 1);
    used[i] = 0;
  }
}
int main() {
  InputData();
  DFS(1, 0); // 1 <= M <= N <= 8
  return 0;
}
