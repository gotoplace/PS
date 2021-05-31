/*
https://www.acmicpc.net/problem/15649 : N과 M (1)
2020KB 24ms

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
=> 순열에 해당됨. nPr = n! / (n - r)!

DFS로 접근, used 배열을 사용하여 조합을 뽑아낸다.
이 때, sol[cnt] = i가 출력할 대상이 된다.
cnt가 M개가 되면 sol 배열을 M개 만큼 출력하고 return한다.

순열, 중복순열, 조합, 중복조합 개념
https://m.blog.naver.com/alwaysneoi/100155625557

순열, 중복순열, 조합, 중복조합 공식
https://bb-dochi.tistory.com/47
https://m.blog.naver.com/honeyeah/220295949101
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
