/*
https://www.acmicpc.net/problem/10974 : 모든 순열
2020KB 20ms

기본 순열 문제
1부터 N까지의 수로 이루어진 수열 출력
N!개 만큼 출력해야 정답 처리됨
N개 중 R개 선택인데, N = R 조건
nPn = N! 이 성립됨.
https://blog.naver.com/honeyeah/110155527947
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (8)

int N;
int used[MAXN +2], sol[MAXN +2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
void PrintNum() {
  for (int i = 0; i < N; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int cnt) {
  if (cnt == N) {
    PrintNum(); return;
  }
  for (int i = 1; i <= N; i++) {
    if (used[i]) continue;
    used[i] = 1; sol[cnt] = i;
    DFS(cnt + 1);
    used[i] = 0;
  }
}
int main() {
  InputData();
  DFS(0);
  return 0;
}
