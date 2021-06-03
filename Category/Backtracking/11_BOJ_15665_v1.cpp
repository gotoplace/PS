/*
https://www.acmicpc.net/problem/15665 : N과 M (11)
2020KB 128ms

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
=> 중복순열을 구하는 문제
& 중복되는 수열을 여러 번 출력하면 안됨

중복순열을 구하되 prev_num과 같은 수는 무시한다.

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
int arr[MAXN + 2], sol[MAXN + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
}
void PrintNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int cnt) {
  if (cnt == M) {
    PrintNum(); return;
  }
  int prev_num = -1;
  for (int i = 0; i < N; i++) {
    if (prev_num == arr[i]) continue;
    prev_num = arr[i];
    sol[cnt] = arr[i];
    DFS(cnt + 1);
  }
}
int main() {
  InputData();
  sort(arr, arr + N);
  DFS(0);
  return 0;
}
