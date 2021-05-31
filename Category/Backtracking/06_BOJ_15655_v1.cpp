/*
https://www.acmicpc.net/problem/15655 : N과 M (6)
2020KB 0ms

N개의 자연수 중에서 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

중복되는 수열을 여러 번 출력하면 안되며
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

N개의 자연수를 입력받고 정렬하는 것 외에 15650 N과 M (2) 조합 문제와 동일한 문제

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
void DFS(int s, int cnt) {
  if (cnt == M) {
    PrintNum(); return;
  }
  for (int i = s; i < N; i++) {
    sol[cnt] = arr[i];
    DFS(i + 1, cnt + 1);
  }
}
int main() {
  InputData();
  sort(arr, arr + N); // idx 0입력된 N개 자연수는 정렬되지 않았음
  DFS(0, 0); // idx 0부터 시작
  return 0;
}
