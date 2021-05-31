/*
https://www.acmicpc.net/problem/15656 : N과 M (7)
2020KB 504ms

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

N개의 자연수를 입력받고 정렬하는 것 외에는 15651 N과 M (3) 중복순열 문제와 동일한 문제
nPir = n^r

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
  for (int i = 0; i < N; i++) {
    sol[cnt] = arr[i];
    DFS(cnt + 1);
  }
}
int main() {
  InputData();
  sort(arr, arr + N);
  DFS(0); // idx 0부터 시작
  return 0;
}
