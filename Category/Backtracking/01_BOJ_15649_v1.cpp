/*
https://www.acmicpc.net/problem/15649 : N과 M (1)
2020KB 24ms

1 ~ N중에서 M개를 선택하는 조합의 경우의 수를 찾는 문제
DFS로 접근, used 배열을 사용하여 조합을 뽑아낸다. 이 때, sol[cnt] = i가 출력할 대상이 된다.
cnt가 M개가 되면 sol 배열을 M개 만큼 출력하고 return한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAXN (8)
int N, M;
int used[MAXN + 2], sol[MAXN + 2];

void PrintNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
}
void DFS(int cnt) {
  if (cnt == M) {
    PrintNum();
    return;
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
