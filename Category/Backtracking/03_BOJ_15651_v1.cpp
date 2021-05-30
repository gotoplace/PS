/*
https://www.acmicpc.net/problem/15651 : N과 M (3)
2020KB 372ms

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
=> 중복 허용. 중복순열
=> nπr = n^r
=> N : 3, M : 3 이면, 27개 경우의 수가 나옴

순열, 중복순열, 조합, 중복조합 개념
https://m.blog.naver.com/alwaysneoi/100155625557

순열, 중복순열, 조합, 중복조합 공식
https://bb-dochi.tistory.com/47
https://m.blog.naver.com/honeyeah/220295949101
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (7)

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
    sol[cnt] = i;
    DFS(cnt + 1);
  }
}
int main() {
  InputData();
  DFS(0);
  return 0;
}
